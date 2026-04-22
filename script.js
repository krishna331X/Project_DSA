let bookings = [];

document.getElementById("bookingForm")?.addEventListener("submit", function(e){

e.preventDefault();

let name = document.getElementById("name").value;
let service = document.getElementById("service").value;
let time = document.getElementById("time").value;

let booking = {
name:name,
service:service,
time:time
};

bookings.push(booking);

localStorage.setItem("bookings", JSON.stringify(bookings));

alert("Booking Added");

});