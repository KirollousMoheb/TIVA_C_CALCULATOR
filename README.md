# Simple Calculator Using TIVA C
# Description

> This a simple Calculator that performs addition,subtraction,multiplication and division by interfacing with a 4x4 Keypad and LCD.

## Table of Contents

- [Connections](#connections)
  * [LCD](#lcd)
  * [KeyPad](#keypad)
- [Files](#files)
  * [Delay](#delay)
  * [KeyPad](#keypad)
  * [LCD](#lcd)
  * [Calcuations](#calculations)
  * [CalculatorBase](#calculatorbase)
  * [Calculator](#calculator)
- [Options](#options)
  * [options.append](#optionsappend)
  * [options.filter](#optionsfilter)
  * [options.slugify](#optionsslugify)
  * [options.bullets](#optionsbullets)
  * [options.maxdepth](#optionsmaxdepth)
  * [options.firsth1](#optionsfirsth1)
  * [options.stripHeadingTags](#optionsstripheadingtags)




## Connections


### LCD



```js
var Remarkable = require('remarkable');
var toc = require('markdown-toc');

function render(str, options) {
  return new Remarkable()
    .use(toc.plugin(options)) // <= register the plugin
    .render(str);
}
```


### KeyPad

```js
toc('# AAA\n## BBB\n### CCC\nfoo').json;

// results in
[ { content: 'AAA', slug: 'aaa', lvl: 1 },
  { content: 'BBB', slug: 'bbb', lvl: 2 },
  { content: 'CCC', slug: 'ccc', lvl: 3 } ]
```



## Files

### Delay



```js
var Remarkable = require('remarkable');
var toc = require('markdown-toc');

function render(str, options) {
  return new Remarkable()
    .use(toc.plugin(options)) // <= register the plugin
    .render(str);
}
```



### KeyPad

Object for creating a custom TOC.

```js
toc('# AAA\n## BBB\n### CCC\nfoo').json;

// results in
[ { content: 'AAA', slug: 'aaa', lvl: 1 },
  { content: 'BBB', slug: 'bbb', lvl: 2 },
  { content: 'CCC', slug: 'ccc', lvl: 3 } ]
```

### LCD



```
<!-- toc -->
- old toc 1
- old toc 2
- old toc 3
<!-- tocstop -->

## abc
This is a b c.

## xyz
This is x y z.
```



### Calculations

As a convenience to folks who wants to create a custom TOC, markdown-toc's internal utility methods are exposed:

```js
var toc = require('markdown-toc');
```

* `toc.bullets()`: render a bullet list from an array of tokens
* `toc.linkify()`: linking a heading `content` string
* `toc.slugify()`: slugify a heading `content` string
* `toc.strip()`: strip words or characters from a heading `content` string
### CalculatorBase

As a convenience to folks who wants to create a custom TOC, markdown-toc's internal utility methods are exposed:

```js
var toc = require('markdown-toc');
```

* `toc.bullets()`: render a bullet list from an array of tokens
* `toc.linkify()`: linking a heading `content` string
* `toc.slugify()`: slugify a heading `content` string
* `toc.strip()`: strip words or characters from a heading `content` string
### Calculator

As a convenience to folks who wants to create a custom TOC, markdown-toc's internal utility methods are exposed:

```js
var toc = require('markdown-toc');
```

* `toc.bullets()`: render a bullet list from an array of tokens
* `toc.linkify()`: linking a heading `content` string
* `toc.slugify()`: slugify a heading `content` string
* `toc.strip()`: strip words or characters from a heading `content` string

## Options

### options.append

Append a string to the end of the TOC.

```js
toc(str, {append: '\n_(TOC generated by Verb)_'});
```

### options.filter

Type: `Function`

Default: `undefined`

Params:

* `str` **{String}** the actual heading string
* `ele` **{Objecct}** object of heading tokens
* `arr` **{Array}** all of the headings objects





```
 
