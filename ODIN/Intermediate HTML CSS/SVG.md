## SVG(Scalable Vector Graphics)

(Material Icon)[https://fonts.google.com/icons?icon.size=24&icon.color=%235f6368]

(Feather Icon)[https://feathericons.com/]

(SVG Editor)[https://yqnn.github.io/svg-path-editor/]

1. SVGs are scalable image format.
2. They will easily scale to any size and retain their quality without increasing their filesize.
3. They're especially useful if need to create and modify your images programatically, because you can change their properties through CSS and JS.

used for:

- Icons
- Graphs/Charts
- Large, Simple images
- Patterned Backgrounds
- Applying effects to other elements via SVG filters

Vector graphics are images defined by math, as opposed to traditional "raster graphics".

- A raster graphic is made up of a collection of tiny, uniformly sized pixels, which are arranged in a two-dimensional grid made up of columns and rows.

With raster graphics, the detail is limited to the size of that pixel grid.

- With vector graphics on the other hand, there's no grid. Instead you have formulas for different shapes and lines. Since these are just formulas, it doesn't matter how large or small you want them to appear-they can scale to any size you want, and it will have no effect on the quality or the size of the file.

- SVGs source-code is **XML**.
  - It is human readable.
  - XML is interoperable with HTML, which means we can put XML directly in HTML file, without any changes, and it should display the image.
  - they become elements in DOM just like HTML elements, so you can target them with CSS.

> Since every single detail of the image need to be written out as XML, they are extremely inefficient at storing complex images.

### Anatomy of SVG

_Figma and Adobe Illustrator are two popular apps that can create SVGs._

- <code>xmlns</code> stands for _XML NameSpace_ . This specified what dialect of XML, you're using.
  Without it, some browsers will not render your image or will render it incorrectly.

- <code>viewBox</code> defined the bounds of your SVG. When you have to define the positions of different points of the elements in your SVG, this is what that's referencing.
  It also defines the aspect ratio and the origin of your SVG.

- <code>class, id</code> : similar to HTML. allows to target an element via CSS or Javascript.
  or to reuse an element via the <code>[use](https://developer.mozilla.org/en-US/docs/Web/SVG/Element/use)</code> element

- Elements such as <code> <circle>, <rect>, <path>, <text></code> are defined by the SVG namespace.

### Embedding SVGs

SVGs can be embedded in your document: linked and inline.

- linking can be done in HTML using <code><img></code>, or link it in your CSS using <code>background-image: url()</code>
  This will still scale properly, but the contents of the SVG will not be accessible from the webpage.

- inline by pasting contents directly to webpages code.
  - inlining SVG allow you to alter the image dynamically via CSS or JavaScript.
  - it makes your code harder to read, makes your page less cacheable, and if it's large SVG it might delay the rest of your HTML from loading.
