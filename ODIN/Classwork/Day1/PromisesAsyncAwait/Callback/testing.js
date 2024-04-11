/*
function loadScript(src) {
  let script = document.createElement("script");
  script.src = src;
  document.head.append(script);
}

loadScript("file.js");
*/
/*
function loadScript(src) {
    let script = document.createElement("script");
    script.src = src;
    document.head.append(script);
  }
  
  loadScript("file.js");
  console.log("Hi this is testing");

  */
/*
  function loadScript(src) {
    let script = document.createElement("script");
    script.src = src;
    document.head.append(script);
  }
  
  loadScript("file.js");
  fun1();
  */
/*
function loadScript(src, callback) {
  debugger;
  let script = document.createElement("script");
  script.src = src;
  script.onload = () => callback(script);
  document.head.append(script);
}
debugger;
loadScript("file.js", () => {
  debugger;
  fun1();
});
*/
/*
function loadScript(src, callback) {
  debugger;
  let script = document.createElement("script");
  script.src = src;
  script.onload = () => callback(script);
  document.head.append(script);
}

debugger;
loadScript(
  "https://cdnjs.cloudflare.com/ajax/libs/lodash.js/3.2.0/lodash.js",
  (script) => {
    debugger;
    alert(`Cool, the script ${script.src} is loaded`);
    alert(_); // _ is a function declared in the loaded script
  }
);
*/
/*
function loadScript(src, callback) {
  debugger;
  let script = document.createElement("script");
  script.src = src;
  script.onload = () => callback(script);
  document.head.append(script);
}
debugger;
loadScript("file.js", (script) => {
  debugger;
  alert(`Cool, the ${script.src} is loaded let's load one more`);
  loadScript("file2.js", (script) => {
    debugger;
    alert(`Cool, the second script is loaded ${script.src}`);
  });
});
*/

function loadScript(src, callback) {
  debugger;
  let script = document.createElement("script");
  script.src = src;
  script.onload = () => {
    callback(null, script);
  };
  script.onerror = () => {
    callback(new Error(`Script load Error for ${src}`));
  };
  document.head.append(script);
}

debugger;
loadScript("//file.js", (error, script) => {
  debugger;
  if (error) {
    alert(error.message);
  } else {
    alert(`${script} loaded successfully`);
  }
});
