type scope =
  | Global(string)
  | GlobalIf(string, bool)
  | Local(string)
  | LocalIf(string, bool);

type cssmodule = Js.Dict.t(string);

let filterEmptyString = List.filter((!==)(""));

let concatWithSpace = String.concat(" ");

let make = (cssmodule: cssmodule, classnames: list(scope)) : string =>
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
  |> filterEmptyString
  |> concatWithSpace;

let join = classname =>
  switch (classname) {
  | Local(name)
  | Global(name) => name
  | LocalIf(name, maybe)
  | GlobalIf(name, maybe) => maybe ? name : ""
  };

let joinMany = (classnames: list(scope)) =>
  classnames |> List.map(join) |> filterEmptyString |> concatWithSpace;

let join2 = (classname, classname2) => joinMany([classname, classname2]);

let join3 = (classname, classname2, classname3) =>
  joinMany([classname, classname2, classname3]);

let join4 = (classname, classname2, classname3, classname4) =>
  joinMany([classname, classname2, classname3, classname4]);
