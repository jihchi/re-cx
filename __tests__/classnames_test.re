open Jest;

open Expect;

describe("Normal version", () => {
  test("fn('foo', 'bar')", () =>
    Classnames.classnamesArrayStr([|"foo", "bar"|]) |> expect |> toBe("foo bar")
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
});
