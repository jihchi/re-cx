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

## Documentation

### API

#### make
#### join
#### join2
#### join3
#### join4
#### joinMany
