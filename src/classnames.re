/* # Normal version */
/* classNames('foo', 'bar'); // => 'foo bar' */
/* classNames('foo', { bar: true }); // => 'foo bar' */
/* classNames({ 'foo-bar': true }); // => 'foo-bar' */
/* classNames({ 'foo-bar': false }); // => '' */
/* classNames({ foo: true }, { bar: true }); // => 'foo bar' */
/* classNames({ foo: true, bar: true }); // => 'foo bar' */
/* // lots of arguments of various types */
/* classNames('foo', { bar: true, duck: false }, 'baz', { quux: true }); // => 'foo bar baz quux' */
/* // other falsy values are just ignored */
/* classNames(null, false, 'bar', undefined, 0, 1, { baz: null }, ''); // => 'bar 1' */

/* # Alternate bind version (for css-modules) */
/* var classNames = require('classnames/bind'); */
/* var styles = { */
/*   foo: 'abc', */
/*   bar: 'def', */
/*   baz: 'xyz' */
/* }; */
/* var cx = classNames.bind(styles); */
/* var className = cx('foo', ['bar'], { baz: true }); // => "abc def xyz" */

/* # Alternate dedupe version */
/* var classNames = require('classnames/dedupe'); */
/* classNames('foo', 'foo', 'bar'); // => 'foo */

