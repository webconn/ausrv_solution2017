#include "reader.h"

#include "tinyxml2.h"
#include <string>

#define TAG_SYSTEM "system"
#define TAG_TASK   "task"

#define ATTR_NAME     "name"
#define ATTR_PERIOD   "period"
#define ATTR_PRIORITY "priority"
#define ATTR_DURATION "duration"
#define ATTR_DEADLINE "deadline"

using namespace std;
using namespace tinyxml2;

static Task readTaskFromElement(XMLElement *elem)
{
        Task t = Task();


        t.name = string(elem->Attribute(ATTR_NAME));

        elem->QueryIntAttribute(ATTR_PERIOD, &t.period);
        elem->QueryIntAttribute(ATTR_PRIORITY, &t.priority);
        elem->QueryIntAttribute(ATTR_DURATION, &t.duration);
        elem->QueryIntAttribute(ATTR_DEADLINE, &t.deadline);

        return t;
}

list<Task> readTasks(const char *filename)
{
        XMLDocument xml;
        list<Task> tasks;

        xml.LoadFile(filename);

        XMLElement *root = xml.FirstChildElement(TAG_SYSTEM);

        // loop through all 'task' elements and fill tasks list
        for (XMLElement *child = root->FirstChildElement(TAG_TASK); child != nullptr; child = child->NextSiblingElement()) {
                if (string(child->Name()) == TAG_TASK) {
                        tasks.push_back(readTaskFromElement(child));
                }
        }

        return tasks;
}

std::ostream& operator<<(std::ostream& o, const Task& t)
{
        o << t.name << "(period " << t.period
                << ", duration " << t.duration
                << ", deadline " << t.deadline
                << ", priority " << t.priority
                << ")";

        return o;
}
