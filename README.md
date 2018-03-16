# re-cx

Classnames helper written in ReasonML

## Example

```ml
open ReCx; /* for "namespace: true" in bsconfig.json */

let cssmodule = Js.Dict.fromList([("foo", "foo_123"), ("bar", "bar_456")]);

let cx = Cx.make(cssmodule);

Js.log(cx([LocalIf("foo", true), LocalIf("bar", false)]));

/* output: foo_123 */
```

## Installation

```bash
yarn add re-cx 
```

Then add `re-cx` to `bs-dependencies` in your `bsconfig.json`:

```json
{
  ...
  "bs-dependencies": ["re-cx"]
}
```

## Usage

```ml
Cx.join2(Global("foo"), GlobalIf("bar", false)); /* => "foo" */
```

#### make

This is for [css-modules](https://github.com/css-modules/css-modules) user. Just like [classnames' bind version](https://github.com/JedWatson/classnames#alternate-bind-version-for-css-modules).

```ml
let cssmodule = Js.Dict.fromList([("foo", "foo_123"), ("bar", "bar_456")]);
let cx = Cx.make(cssmodule);
cx([Local("foo"), LocalIf("bar", false)]); /* => "foo_123" */
```

#### join

```ml
Cx.join(Local("foo")); /* => "foo" */
```

#### join2

```ml
Cx.join2(Local("foo"), LocalIf("bar", false)); /* => "foo" */
```

#### join3

```ml
Cx.join3(Local("foo"), LocalIf("bar", false), Local("baz")); /* => "foo baz" */
```

#### join4

```ml
Cx.join4(Local("foo"), LocalIf("bar", false), Local("baz"), Local("woo")); /* => "foo baz woo" */
```

#### joinMany

```ml
Cx.joinMany([Local("foo"), LocalIf("bar", false), Local("baz"), Local("woo")]); /* => "foo baz woo" */
```

## Note

This library is inspired by https://github.com/alexfedoseev/re-classnames
