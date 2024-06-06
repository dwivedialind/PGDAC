const modal = document.querySelector(".modal");
const openButton = document.querySelector(".open-button");
const closeButton = document.querySelector(".close-button");

openButton.addEventListener("click", () => {
  modal.show();
});

closeButton.addEventListener("click", () => {
  modal.close();
});
