open Jest;

open Expect;

describe("Cx", () => {
  describe("without css-module", () => {
    describe("join", () => {
      test("Global", () =>
        Cx.join(Global("foo")) |> expect |> toBe("foo")
      );
      test("GlobalIf true", () =>
        Cx.join(GlobalIf("foo", true)) |> expect |> toBe("foo")
      );
      test("GlobalIf false", () =>
        Cx.join(GlobalIf("foo", false)) |> expect |> toBe("")
      );
      test("Local", () =>
        Cx.join(Local("foo")) |> expect |> toBe("foo")
      );
      test("LocalIf true", () =>
        Cx.join(LocalIf("foo", true)) |> expect |> toBe("foo")
      );
      test("LocalIf false", () =>
        Cx.join(LocalIf("foo", false)) |> expect |> toBe("")
      );
    });
    describe("join2", () => {
      test("Global", () =>
        Cx.join2(Global("foo"), Global("bar")) |> expect |> toBe("foo bar")
      );
      test("GlobalIf true", () =>
        Cx.join2(GlobalIf("foo", true), GlobalIf("bar", true))
        |> expect
        |> toBe("foo bar")
      );
      test("GlobalIf false", () =>
        Cx.join2(GlobalIf("foo", false), GlobalIf("bar", false))
        |> expect
        |> toBe("")
      );
      test("Local", () =>
        Cx.join2(Local("foo"), Local("bar")) |> expect |> toBe("foo bar")
      );
      test("LocalIf true", () =>
        Cx.join2(LocalIf("foo", true), LocalIf("bar", true))
        |> expect
        |> toBe("foo bar")
      );
      test("LocalIf false", () =>
        Cx.join2(LocalIf("foo", false), LocalIf("bar", false))
        |> expect
        |> toBe("")
      );
    });
  });
  describe("with css-module", () => {
    let cssmodule =
      Js.Dict.fromList([("foo", "foo_123"), ("bar", "bar_456")]);
    let cx = Cx.make(cssmodule);
    test("Global", () =>
      cx([Global("baz"), Global("")]) |> expect |> toBe("baz")
    );
    test("GlobalIf", () =>
      cx([
        GlobalIf("foo", true),
        GlobalIf("bar", false),
        GlobalIf("", true),
        GlobalIf("", false),
      ])
      |> expect
      |> toBe("foo")
    );
    test("Local", () =>
      cx([Local("foo"), Local("bar"), Local("")])
      |> expect
      |> toBe("foo_123 bar_456")
    );
    test("LocalIf", () =>
      cx([
        LocalIf("foo", true),
        LocalIf("bar", false),
        LocalIf("", true),
        LocalIf("", false),
      ])
      |> expect
      |> toBe("foo_123")
    );
  });
});
