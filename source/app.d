import std.stdio;
import std.conv;

import vibe.d;

import chapters;

void showError(HTTPServerRequest req, HTTPServerResponse res, HTTPServerErrorInfo error)
{
    res.renderCompat!("error.dt",
    HTTPServerRequest, "req",
    HTTPServerErrorInfo, "error")(req, error);
}

void showChapter(HTTPServerRequest req, HTTPServerResponse res)
{
    scope(failure) throw new HTTPStatusException(404);
    auto chapters = Chapter.readChapters();
    const index = to!uint(req.params["page"]) - 1;
    chapters[index].render(req, res);
}

void showHome(HTTPServerRequest req, HTTPServerResponse res) {
    const auto chapters = Chapter.readChapters();
    res.renderCompat!("home.dt", const Chapter[], "chapters")(chapters);
}

shared static this()
{
    const string urlBase = "/td_imac";

    auto router = new URLRouter;

    auto fileSettings = new HTTPFileServerSettings(urlBase);
    router.get(urlBase~"/*", serveStaticFiles("public", fileSettings));
    router.get(urlBase~"/:page", &showChapter);
    router.get(urlBase~"/", &showHome);

    auto settings = new HTTPServerSettings;
    settings.port = 8080;
    settings.errorPageHandler = toDelegate(&showError);

    listenHTTP(settings, router);
}
