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
	auto router = new URLRouter;
	router.get("*", serveStaticFiles("public"));
	router.get("/:page", &showChapter);
	router.get("/", &showHome);

	auto settings = new HTTPServerSettings;
	settings.port = 8080;
	settings.errorPageHandler = toDelegate(&showError);

	listenHTTP(settings, router);
}
