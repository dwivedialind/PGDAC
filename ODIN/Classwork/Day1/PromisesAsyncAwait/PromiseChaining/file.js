/*
function loadScript(src, callback) {
  let script = document.createElement("script");
  script.src = src;
  script.onload = () => {
    callback(script);
  };
  script.onerror = () => {
    callback(null, new Error(`Fail ${src}`));
  };
  document.head.append(script);
}

loadScript("file1.js", (script, error) => {
  if (error) alert(error);
  else {
    fun();
    alert(script);
    loadScript("file2.js", (script, error) => {
      if (error) alert(error);
      else {
        fun();
        alert(script);
      }
    });
  }
});
*/

/*
function loadScript(src) {
  debugger;
  return new Promise((resolve, reject) => {
    let script = document.createElement("script");
    script.src = src;
    script.onload = () => resolve(script);
    script.onerror = () => reject(new Error(`Fail ${src}`));
    document.head.append(script);
  });
}

debugger;
loadScript("file1.js")
  .then(
    (result) => {
      alert(result);
      fun();
      return loadScript("file2.js");
    },
    (error) => {
      alert(error);
    }
  )
  .then(
    (result) => {
      debugger;
      alert(result);
      fun();
    },
    (error) => {
      alert(error);
    }
  );
*/
