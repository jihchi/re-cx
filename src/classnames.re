type obj = Js.Dict.t(Js.boolean);

[@bs.module] [@bs.splice]
external classnamesArrayStr : array(string) => string = "classnames";

[@bs.module] external classnamesDict : obj => string = "classnames";

[@bs.module] [@bs.splice]
external classnamesArrayDict : array(obj) => string = "classnames";

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
type classnames =
  | Global(string)
  | GlobalIf(string, bool)
  | Local(string)
  | LocalIf(string, bool);

type cssmodule = Js.Dict.t(string);

let makeCx = (cssmodule: cssmodule, classnames: list(classnames)) : string =>
  classnames
  |> List.map(classname =>
       switch (classname) {
       | Global(name) => name
       | GlobalIf(name, maybe) => maybe ? name : ""
       | Local(key) =>
         Js.Dict.get(cssmodule, key) |> Js.Option.getWithDefault(key)
       | LocalIf(key, maybe) =>
         maybe ?
           Js.Dict.get(cssmodule, key) |> Js.Option.getWithDefault(key) : ""
       }
     )
  |> List.filter(classname => classname !== "")
  |> String.concat(" ");
