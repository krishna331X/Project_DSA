let bookingQueue = [];
let serviceStack = [];

function bookService(service){

let name = prompt("Enter your name");

let customer = {
name:name,
service:service
};

bookingQueue.push(customer);

displayQueue();
}

function displayQueue(){

let list = document.getElementById("queueList");
list.innerHTML="";

bookingQueue.forEach((c,index)=>{

let li=document.createElement("li");
li.innerText = (index+1) + ". " + c.name + " - " + c.service;

list.appendChild(li);

});

}

function serveCustomer(){

if(bookingQueue.length==0){
alert("No customers");
return;
}

let served = bookingQueue.shift();

serviceStack.push(served);

displayQueue();
displayHistory();

}

function displayHistory(){

let list = document.getElementById("historyList");
list.innerHTML="";

serviceStack.slice().reverse().forEach(c=>{

let li=document.createElement("li");
li.innerText = c.name + " - " + c.service;

list.appendChild(li);

});

}

function undoService(){

if(serviceStack.length==0){
alert("Nothing to undo");
return;
}

let last = serviceStack.pop();

alert(last.name + " service removed");

displayHistory();

}