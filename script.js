let bookings = JSON.parse(localStorage.getItem("bookings")) || [];

/* ADD BOOKING (QUEUE) */

document.getElementById("bookingForm")?.addEventListener("submit", function(e){

e.preventDefault();

let name = document.getElementById("name").value;
let service = document.getElementById("service").value;
let time = document.getElementById("time").value;

let booking = {name, service, time};

bookings.push(booking);

localStorage.setItem("bookings", JSON.stringify(bookings));

alert("Appointment Booked");

});


/* DISPLAY BOOKINGS */

function displayBookings(){

let table = document.getElementById("tableData");

if(!table) return;

table.innerHTML="";

bookings.forEach((b,i)=>{

let row = `<tr>

<td>${b.name}</td>
<td>${b.service}</td>
<td>${b.time}</td>

</tr>`;

table.innerHTML += row;

});

}


/* SEARCH BOOKING */

function searchBooking(){

let name = document.getElementById("search").value.toLowerCase();

let result = bookings.find(b => b.name.toLowerCase() === name);

if(result){

alert("Booking Found: "+result.service+" at "+result.time);

}else{

alert("Booking Not Found");

}

}


/* CANCEL LAST BOOKING (STACK) */

function cancelLast(){

bookings.pop();

localStorage.setItem("bookings", JSON.stringify(bookings));

displayBookings();

}


/* SORT BOOKINGS BY TIME */

function sortBookings(){

bookings.sort((a,b)=> a.time.localeCompare(b.time));

localStorage.setItem("bookings", JSON.stringify(bookings));

displayBookings();

}


displayBookings();