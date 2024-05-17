#### When should you NOT use HTML tables?

- should be used to store tabular data.
- don't use for web page layout.

  - Layout tables reduce accessibility for visually impaired users: as screen readers used tags in HTML page and read out the contents to the user.
  - Table produce tag soup: table layouts generally involve more complex markup structures than proper layout techniques. This can result in the code being harder to write, maintain and debug.

  - Tables are not automatically responsive.
    when we use proper layout containers as <code>header, section, article or div</code>, their width default to 100% of their parent element. Tables on the other hand are sized by default according to their content, so extra measures needed to be taken to get table layout styling work effectively across a variety of devices.

#### Why are headers useful?

- easier to find data you're looking for, when header clearly standout.
- bold and centered by default.
- table header associate all the data in same row and column, makes it easy for screen reader.

#### Styling Table using \<col>\<colgroup>

For styling entire column of data all in one place.

```html
<table>
  <colgroup>
    <col />
    <col style="background-color: yellow" />
  </colgroup>
  <tr>
    <th>Data 1</th>
    <th>Data 2</th>
  </tr>
  <tr>
    <td>Calcutta</td>
    <td>Orange</td>
  </tr>
  <tr>
    <td>Robots</td>
    <td>Jazz</td>
  </tr>
</table>
```

> We define two "style columns", provide styling for each column

**If we want styling information for both columns**

```html
<colgroup>
  <col style="background-color: yellow" span="2" />
</colgroup>
```

#### Giving Caption to your table

**_A Caption is placed directly beneath the table tag._**

> Useful for impaired users, the user can rely on caption and then decide whether to read out table in greater detail.

```html
<table>
  <caption>
    This is table Example
  </caption>
</table>
```

#### Adding structure to your table

- Using <code>thead , tbody</code> don't have anything to with accessibility.
- Useful for styling and layout, adding CSS to your tables.

> <code>tbody</code> is always added in your code implicitly, if you don't specify it.

#### Nesting tables

- It is possible to nest table inside another one
- not advised, make markup more confusing and less accessible for screen reader users.

#### Accessibility

- Using headers for rows and cols.
