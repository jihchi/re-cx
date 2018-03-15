open Jest;

open Expect;

describe("Normal version", () => {
  test("fn('foo', 'bar')", () =>
    Classnames.classnamesArrayStr([|"foo", "bar"|])
    |> expect
    |> toBe("foo bar")
  );
  test("fn({ 'foo-bar': true })", () =>
    Classnames.classnamesDict(Js.Dict.fromList([("foo-bar", Js.true_)]))
    |> expect
    |> toBe("foo-bar")
  );
  test("fn({ 'foo-bar': false })", () =>
    Classnames.classnamesDict(Js.Dict.fromList([("foo-bar", Js.false_)]))
    |> expect
    |> toBe("")
  );
  test("fn({ foo: true }, { bar: true })", () =>
    Classnames.classnamesArrayDict([|
      Js.Dict.fromList([("foo", Js.true_)]),
      Js.Dict.fromList([("bar", Js.true_)]),
    |])
    |> expect
    |> toBe("foo bar")
  );
  let cssmodule =
    Js.Dict.fromList([("foo", "foo_123"), ("bar", "bar_456")]);
  test("css-module Global", () =>
    Classnames.makeCx(cssmodule, [Global("baz"), Global("")])
    |> expect
    |> toBe("baz")
  );
  test("css-module GlobalIf", () =>
    Classnames.makeCx(
      cssmodule,
      [
        GlobalIf("foo", true),
        GlobalIf("bar", false),
        GlobalIf("", true),
        GlobalIf("", false),
      ],
    )
    |> expect
    |> toBe("foo")
  );
  test("css-module Local", () =>
    Classnames.makeCx(cssmodule, [Local("foo"), Local("bar"), Local("")])
    |> expect
    |> toBe("foo_123 bar_456")
  );
  test("css-module LocalIf", () =>
    Classnames.makeCx(
      cssmodule,
      [
        LocalIf("foo", true),
        LocalIf("bar", false),
        LocalIf("", true),
        LocalIf("", false),
      ],
    )
    |> expect
    |> toBe("foo_123")
  );
});
