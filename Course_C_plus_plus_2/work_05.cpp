#include <exception>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>
#include <tuple>
#include <utility>

using namespace std;

TaskStatus Next(TaskStatus task_status) {
    return static_cast<TaskStatus>(static_cast<int>(task_status) + 1);
}

void RemoveZeros(TasksInfo& tasks_info) {

    vector<TaskStatus> statuses_to_remove;
    for (const auto& task_item : tasks_info) {
        if (task_item.second == 0) {
            statuses_to_remove.push_back(task_item.first);
        }
    }
    for (const auto status : statuses_to_remove) {
        tasks_info.erase(status);
    }
}

class TeamTasks {
public:

    const TasksInfo& GetPersonTasksInfo(const string& person) const {        
        return personTasks.at(person);  
    }


    void AddNewTask(const string& person) {
        personTasks[person][TaskStatus::NEW]++;
    }


    tuple<TasksInfo, TasksInfo> PerformPersonTasks(const string& person, int task_count) {
        TasksInfo t1, t2, &tasks = personTasks[person];
        
        for (TaskStatus status = TaskStatus::NEW; status != TaskStatus::DONE; status = Next(status)) {
            t1[Next(status)] = min(task_count, tasks[status]);
           
            task_count -= t1[Next(status)];
        }
        for (TaskStatus status = TaskStatus::NEW; status != TaskStatus::DONE; status = Next(status)) {
            t2[status] = tasks[status] - t1[Next(status)];
            tasks[status] += t1[status] - t1[Next(status)];
        }
        tasks[TaskStatus::DONE] += t1[TaskStatus::DONE];

        RemoveZeros(t1);
        RemoveZeros(t2);
        RemoveZeros(personTasks.at(person));

        return { t1, t2 };

    }
private:
    map<string, TasksInfo> personTasks;
};