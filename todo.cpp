#include "todo.h"
#include <stdexcept>

void TodoList::init() {
    // TODO: set size to 0 and all task pointers to nullptr
    size = 0;
    for (int i = 0; i < MAX_TASKS; i++) {
        tasks[i] = nullptr;
    }
}

void TodoList::destroy() {
    // TODO: delete all tasks and reset pointers
}

int TodoList::string_length(const char* str) const {
    // TODO: return the number of characters before '\0'
    int length = 0;
    while (str[length] != '\0') {length++;}
    return length;
}

void TodoList::string_copy(char* dest, const char* src) const {
    // TODO: copy characters from src to dest
    int length = string_length(src);
    for (int i = 0; i < length + 1; i++) {dest[i] = src[i];}
}

void TodoList::add_task(const char* task) {
    // TODO: if full, throw. otherwise allocate and copy new task
    if (size == MAX_TASKS) {throw std::length_error("Add Too Many Tasks Throws");}
    tasks[size] = new char[string_length(task) + 1];
    string_copy(tasks[size], task);
    size++;
}

void TodoList::remove_task(int index) {
    // TODO: check bounds, delete task, shift left
    if ((0 <= index) && (index < size)) {
        for (int i = index; i < size - 1; i++) {string_copy(tasks[i], tasks[i + 1]);}
    tasks[size - 1] = nullptr;
    size--;
    }
    else {
        throw std::out_of_range("Remove Invalid Index Throws");
    }
}

const char** TodoList::get_pending_tasks(int& count) const {
    // TODO: set count and return task array
    count = size;
    const char** tasksArray = new const char*[size];
    for (int i = 0; i < size; i++) {
        char* task = new char[string_length(tasks[i]) + 1];
        string_copy(task, tasks[i]);
        tasksArray[i] = task;
        // delete[] task;
    }
    return tasksArray;
}

// int main() {
//     TodoList todo;
//     todo.init();
//     todo.add_task("Write code");

//     int count;
//     const char** tasks = todo.get_pending_tasks
// }