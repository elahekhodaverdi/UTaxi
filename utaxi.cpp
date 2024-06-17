#include "utaxi.hpp"
using namespace std;
void Utaxi::process(char *filename)
{
    input_output.read_location_data_file(data, filename);
    Server server(5000);
    server.get("/", new ShowPage("static/home.html"));
    server.get("/cost.png", new ShowImage("static/cost.png"));
    server.get("/locationicon.jpeg", new ShowImage("static/locationicon.jpeg"));
    server.get("/signup-form", new ShowPage("static/signup.html"));
    server.get("/taxi.png", new ShowImage("static/taxi.png"));
    server.get("/style.css", new ShowPage("css/style.css"));
    server.get("/logo.png", new ShowImage("static/logo.png"));
    server.get("/back.jpeg", new ShowImage("static/back.jpeg"));
    server.get("/ask-trip-form", new ShowPage("static/ask-for-trip.html"));
    server.get("/get-trip-form", new ShowPage("static/get-trip-form.html"));
    server.get("/trip-manager", new ShowPage("static/trip-manager.html"));
    server.get("/cost-form", new ShowPage("static/cost-form.html"));
    server.get("/BadRequest", new ResponseHandler("template/message.html", "Bad Request"));
    server.get("/NotFound", new ResponseHandler("template/message.html", "Not Found"));
    server.get("/PermissionDenied", new ResponseHandler("template/message.html", "Permission Denied"));
    server.get("/OK", new ResponseHandler("template/message.html", "OK"));
    server.get("/Empty", new ResponseHandler("template/message.html", "Empty"));

    server.post("/signup", new SignUpHandler(&data));
    server.post("/post-trip", new PostTripHandler(&data, "template/message.html"));
    server.get("/get-cost", new GetCostHandler(&data, "template/message.html"));
    server.get("/trips", new GetTripsHandler(&data));
    server.post("/finish", new FinishHandler(&data));
    server.post("/accept", new AcceptHandler(&data));
    server.post("/delete", new DeleteHandler(&data));
    server.run();
}