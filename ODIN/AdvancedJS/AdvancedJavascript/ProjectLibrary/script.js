const myLibrary = [];

function Book() {
  const titleInput = document.getElementById("title");
  const authorInput = document.getElementById("author");
  const pagesInput = document.getElementById("pages");
  const readInput = document.getElementById("read");

  const book = {
    title: titleInput.value,
    author: authorInput.value,
    pages: pagesInput.value,
    read: readInput.value,
  };
  myLibrary.push(book);
}

function addBookToLibrary() {
  const tableInput = document.getElementById("tableDisplay");
  myLibrary.forEach((book) => {
    console.log(book);
    tableInput.innerHTML = `
    <tr>
        <td>${book.title}</td>
        <td>${book.author}</td>
        <td>${book.pages}</td>
        <td>${book.read}</td>
    </tr>
    `;
  });
}
