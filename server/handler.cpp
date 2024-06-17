#include "handler.hpp"
#include "../utaxi.hpp"
using namespace std;
SignUpHandler::SignUpHandler(Data *_data)
{
    data = _data;
}
Response *SignUpHandler::callback(Request *req)
{
    try
    {
        string username = req->getBodyParam(USERNAME);
        string role = req->getBodyParam(ROLE);
        PostRequest *request = new PostRequest;
        vector<string> command = {USERNAME, username, ROLE, role};
        request->signup(*data, command);
        return Response::redirect("/OK");
    }
    catch (BadRequest &ex)
    {
        return Response::redirect("/BadRequest");
    }
    catch (NotFound &ex)
    {
        return Response::redirect("/NotFound");
    }
    catch (PermissionDenied &ex)
    {
        return Response::redirect("/PermissionDenied");
    }
}

GetCostHandler::GetCostHandler(Data *_data, string filePath) : TemplateHandler(filePath)
{
    data = _data;
}

map<string, string> GetCostHandler::handle(Request *req)
{
    map<string, string> result;
    try
    {
        string username = req->getQueryParam(USERNAME);
        string destination = req->getQueryParam(DESTINATION);
        string origin = req->getQueryParam(ORIGIN);
        string in_hurry = req->getQueryParam(IN_HURRY);
        double _cost = data->get_cost(username, destination, origin, in_hurry);
        stringstream stream;
        stream << fixed << setprecision(0) << _cost;
        string cost = stream.str();
        string content = "Your Trip's Cost is: " + cost;
        result["content"] = content;
        return result;
    }
    catch (BadRequest &ex)
    {
        result["content"] = BAD_REQUEST_ERROR;
        return result;
    }
    catch (NotFound &ex)
    {
        result["content"] = NOT_FOUND_ERROR;
        return result;
    }
    catch (PermissionDenied &ex)
    {
        result["content"] = PERMISSION_DENIED_ERROR;
        return result;
    }
}
PostTripHandler::PostTripHandler(Data *_data, std::string filePath)
    : TemplateHandler(filePath)
{
    data = _data;
}
map<string, string> PostTripHandler::handle(Request *req)
{
    map<string, string> result;
    try
    {
        int id = data->post_trip(req->getBodyParam(USERNAME), req->getBodyParam(ORIGIN), req->getBodyParam(DESTINATION), req->getBodyParam(IN_HURRY));
        string content = "Your Trip ID is: " + to_string(id);
        result["content"] = content;
        return result;
    }
    catch (BadRequest &ex)
    {
        result["content"] = BAD_REQUEST_ERROR;
        return result;
    }
    catch (NotFound &ex)
    {
        result["content"] = NOT_FOUND_ERROR;
        return result;
    }
    catch (PermissionDenied &ex)
    {
        result["content"] = PERMISSION_DENIED_ERROR;
        return result;
    }
}

GetTripsHandler::GetTripsHandler(Data *_data)
{
    data = _data;
}
Response *GetTripsHandler::callback(Request *req)
{
    try
    {
        Response *res = new Response;
        res->setHeader("Content-Type", "text/html");
        string username = req->getQueryParam(USERNAME);
        vector<string> command = {USERNAME, username, ID, req->getQueryParam(ID), SORT_BY_COST, req->getQueryParam(SORT_BY_COST)};
        GetRequest *request = new GetRequest;
        vector<Trip *> trips = request->trip(*data, command);
        ostringstream body;
        if (trips.size())
        {
            body << "<!DOCTYPE html>" << endl
                 << "<html>" << endl
                 << "<link rel='stylesheet' href='style.css'>"
                 << "<meta charset='UTF-8'>"
                 << "<title>UTAXI</title>"
                 << "<body>" << endl
                 << "<form action='trips' method='get'>" << endl
                 << "<input type='hidden' name='username' value='" << username << "' />" << endl
                 << "<input type='hidden' name='sort_by_cost' value='yes'/>" << endl
                 << "<div class='table_input'>" << endl
                 << "<input type='submit' value='Sort By Cost' />"
                 << "<input type='submit' formaction='/' value='Back to Home' />" << endl
                 << "</div>" << endl
                 << "</form>" << endl
                 << "<table>" << endl
                 << "<tr>" << endl
                 << "<th>ID</th>" << endl
                 << "<th>Passenger</th>" << endl
                 << "<th>Origin</th>" << endl
                 << "<th>Destination</th>" << endl
                 << "<th>Cost</th>" << endl
                 << "<th>Status</th>" << endl
                 << "<th>Accept</th>" << endl
                 << "<th>Finish</th>" << endl
                 << "</tr>" << endl;
            for (auto &trip : trips)
                trip->complete_body_response(body, username);
            body << "</table>" << endl;
            body << "</body>" << endl
                 << "</html>" << endl;
            res->setBody(body.str());
            return res;
        }
        else
            return Response::redirect("/Empty");
    }
    catch (BadRequest &ex)
    {
        return Response::redirect("/BadRequest");
    }
    catch (NotFound &ex)
    {
        return Response::redirect("/NotFound");
    }
    catch (PermissionDenied &ex)
    {
        return Response::redirect("/PermissionDenied");
    }
}

FinishHandler::FinishHandler(Data *_data)
{
    data = _data;
}
Response *FinishHandler::callback(Request *req)
{
    try
    {
        string username = req->getBodyParam(USERNAME);
        string id = req->getBodyParam(ID);
        PostRequest *request = new PostRequest;
        vector<string> command = {USERNAME, username, ID, id};
        request->finish(*data, command);
        return Response::redirect("/OK");
    }
    catch (BadRequest &ex)
    {
        return Response::redirect("/BadRequest");
    }
    catch (NotFound &ex)
    {
        return Response::redirect("/NotFound");
    }
    catch (PermissionDenied &ex)
    {
        return Response::redirect("/PermissionDenied");
    }
}

AcceptHandler::AcceptHandler(Data *_data)
{
    data = _data;
}
Response *AcceptHandler::callback(Request *req)
{
    try
    {
        string username = req->getBodyParam(USERNAME);
        string id = req->getBodyParam(ID);
        PostRequest *request = new PostRequest;
        vector<string> command = {USERNAME, username, ID, id};
        request->accept(*data, command);
        return Response::redirect("/OK");
    }
    catch (BadRequest &ex)
    {
        return Response::redirect("/BadRequest");
    }
    catch (NotFound &ex)
    {
        return Response::redirect("/NotFound");
    }
    catch (PermissionDenied &ex)
    {
        return Response::redirect("/PermissionDenied");
    }
}

DeleteHandler::DeleteHandler(Data *_data)
{
    data = _data;
}
Response *DeleteHandler::callback(Request *req)
{
    try
    {
        string username = req->getBodyParam(USERNAME);
        string id = req->getBodyParam(ID);
        Delete *request = new Delete;
        vector<string> command = {USERNAME, username, ID, id};
        request->delete_trip(*data, command);
        return Response::redirect("/OK");
    }
    catch (BadRequest &ex)
    {
        return Response::redirect("/BadRequest");
    }
    catch (NotFound &ex)
    {
        return Response::redirect("/NotFound");
    }
    catch (PermissionDenied &ex)
    {
        return Response::redirect("/PermissionDenied");
    }
}

ResponseHandler::ResponseHandler(std::string filePath, std::string _message)
    : TemplateHandler(filePath)
{
    message = _message;
}
std::map<std::string, std::string> ResponseHandler::handle(Request *)
{
    map<string, string> result;
    result["content"] = message;
    return result;
}
