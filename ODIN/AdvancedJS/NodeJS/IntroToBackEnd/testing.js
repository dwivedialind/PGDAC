const element = document.getElementById("myId");
const inputBox = document.getElementById("myIP");
element.addEventListener("click", (event) => {
  console.log(event.target.value);
});
