#include <iostream>
#include <unordered_map>
#include <stack>
#include <string>
#include <iomanip>

using namespace std;
//TASK A

class TaskNode
{
public:
	string tasktitle;
	string category;
	int priority;
	TaskNode* next;

	TaskNode()
	{
		tasktitle = " ";
		category = " ";
		priority = 0;
		next = NULL;
	}
};

class TaskLinkedList
{
public:

	TaskNode* head = NULL;

	bool isempty()
	{
		if (head == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void addTask( string t  , string cat , int p)
	{
		TaskNode* newtask = new TaskNode();
		newtask->tasktitle = t;
		newtask->category = cat;
		newtask->priority = p;
		newtask->next = NULL;

		TaskNode* temp = head;

		if (isempty())
		{
			head = newtask;
			cout << "Task "<<t<<" added successfuly"<< endl;
			cout << endl;
		}

		else if (newtask->priority < head->priority)
		{
			newtask->next = head;
			head = newtask;
			cout << "Task "<<t<<" added successfuly: " << endl;
			cout << endl;
		}

		else
		{
			while (temp->next != NULL && temp->next->priority <= newtask->priority)
			{
				temp = temp->next;
			}
			newtask->next = temp->next;
			temp->next = newtask;
			cout << "Task " << t << " added successfuly: " << endl;
			cout << endl;
		}
	}

	void removeTask(string t)
	{
		TaskNode* delptr=head;
		TaskNode* temp = head;
		if (isempty())
		{
			cout << "There is no tasks to remove!" << endl;
			cout << endl;
		}
		else if (head->tasktitle == t)
		{
			head = head->next;
			delete delptr;
			cout << "Task " << t << " removed successfuly!" << endl;
			cout << endl;
		}
		else
		{
			while (temp->next != NULL && temp->next->tasktitle != t)
			{
				temp = temp->next;
			}

			if (temp->next == NULL)
			{
				cout << "Task " << t << " was not found!" << endl;
				cout << endl;
			}
			else
			{
				delptr = temp->next;
				temp->next = temp->next->next;
				delete delptr;
				cout << "Task " << t << " removed successfuly!" << endl;
				cout << endl;
			}
		}
	}

	bool searchTaskTitle(string t)
	{
		TaskNode* temp = head;

		if (isempty())
		{
			cout << "No tasks available to search for!" << endl;
			cout << endl;
			return false;
		}
		while (temp != NULL)
		{
			if (temp->tasktitle == t)
			{
				cout << "Task found: " << temp->tasktitle << endl;
				cout << endl;
				return true;
			}
			temp = temp->next;
		}
		cout << "Task not found!" << endl;
		cout << endl;
		return false;
	}

	void searchTaskCategory(string cat)
	{
		TaskNode* temp = head;

		if (isempty())
		{
			cout << "No categories to search for!" << endl;
			cout << endl;
		}
		else
		{
			while (temp != NULL && temp->category != cat)
			{
				temp = temp->next;
			}
			if (temp == NULL)
			{
				cout << "No tasks found in category "<<cat<< endl;
				cout << endl;
			}
			else
			{
				cout << "Tasks in category " << cat <<" :"<< endl;
				cout << endl;
				while (temp != NULL)
				{
					if (temp->category == cat)
					{
						cout << "Title: " << temp->tasktitle << " " << "Priority: " << temp->priority << " " << endl;
						cout << endl;
					}
					temp = temp->next;
				}
			}
		}

	}

	void displayTasks()
	{
		TaskNode* temp = head;
		if (isempty())
		{
			cout << "No tasks to display!" << endl;
			cout << endl;
		}
		else
		{
			while (temp != NULL)
			{
				cout << "Task priority: " << temp->priority << endl;
				cout << endl;
				cout << "Task category: " << temp->category << endl;
				cout << endl;
				cout << "Task title: " << temp->tasktitle << endl;
				cout << endl;
				temp = temp->next;
			}
		}
	}

};

//TASK B

const int MAX_EVENTS = 100; // Define the maximum number of events

struct Event {
	string title;
	int hour; // Event hour
	int minute; // Event minute
	string description;

	bool operator<(const Event& other) const {
		if (hour == other.hour) {
			return minute < other.minute;
		}
		return hour < other.hour;
	}
	bool operator>(const Event& other) const {
		if (hour == other.hour) {
			return minute > other.minute;
		}
		return hour > other.hour;
	}
};
class MinHeap {
private:
	Event events[MAX_EVENTS];
	int size;

	int getParent(int i) { return (i - 1) / 2; }
	int getLeftChild(int i) { return 2 * i + 1; }
	int getRightChild(int i) { return 2 * i + 2; }

	void heapifyUp(int index) {
		if (index == 0) return;

		int parent = getParent(index);
		if (events[index] > events[parent]) {
			swap(events[index], events[parent]);
			heapifyUp(parent);
		}
	}

	void heapifyDown(int index) {
		int left = getLeftChild(index);
		int right = getRightChild(index);
		int smallest = index;

		if (left < size && events[left] > events[smallest])
			smallest = left;
		if (right < size && events[right] > events[smallest])
			smallest = right;

		if (smallest != index) {
			swap(events[index], events[smallest]);
			heapifyDown(smallest);
		}
	}

public:
	MinHeap() : size(0) {}

	bool isEmpty() const { return size == 0; }

	void addEvent(const string& title, int hour, int minute, const string& description) {
		if (size >= MAX_EVENTS) {
			cout << "Heap is full. Cannot add more events.\n";
			return;
		}

		events[size].title = title;
		events[size].hour = hour;
		events[size].minute = minute;
		events[size].description = description;
		size++;

		heapifyUp(size - 1);
		cout << "Event added successfully.\n";
	}

	void removeNextEvent() {
		if (isEmpty()) {
			cout << "No events to remove.\n";
			return;
		}

		cout << "Removing event: " << events[0].title << "\n";
		events[0] = events[size - 1];
		size--;
		heapifyDown(0);
	}

	void viewNextEvent() const {
		if (isEmpty()) {
			cout << "No upcoming events.\n";
			return;
		}

		cout << "Next Event:\n";
		cout << "Title: " << events[0].title << "\n";
		cout << "Time: " << setw(2) << setfill('0') << events[0].hour << ":" << setw(2) << setfill('0') << events[0].minute << "\n";
		cout << "Description: " << events[0].description << "\n";
	}

	void displayAllEvents() {
		if (isEmpty()) {
			cout << "No events to display.\n";
			return;
		}

		MinHeap tempHeap = *this; // Create a copy of the heap to sort
		tempHeap.sortClosestFirst();

		cout << "All Events (Closest First):\n";
		for (int i = 0; i < tempHeap.size; i++) {
			cout << "Title: " << tempHeap.events[i].title
				<< ", Time: " << setw(2) << setfill('0') << tempHeap.events[i].hour << ":" << setw(2) << setfill('0') << tempHeap.events[i].minute
				<< ", Description: " << tempHeap.events[i].description << "\n";
		}
	}

	void sortClosestFirst() {
		int originalSize = size;
		for (int i = size - 1; i > 0; i--) {
			swap(events[0], events[i]);
			size--;
			heapifyDown(0);
		}
		size = originalSize; // Restore original size
	}
};


//TASK C

class NoteTaking
{
public:
	const int tablesize = 10;
	struct notes
	{
		stack<string> content;
		stack<string> title;
		notes* next;
	};
	notes* table = new notes[tablesize];
	int hash(string key)
	{
		int sum = 0;
		for (int i = 0; i < key.length(); i++)
		{
			sum += key[i];
		}
		return sum % tablesize;
	}
	void addNote(string title, string cont)
	{
		int i = hash(title);

		// Case 1: No collision, add note to the primary table entry
		if (table[i].content.empty()) {
			table[i].title.push(title);
			table[i].content.push(cont);
			table[i].next = NULL; // Ensure the next pointer is NULL
		}
		// Case 2: Collision, handle via chaining
		else {
			notes* temp = &table[i];

			// Traverse to the end of the chain
			while (temp->next) {
				temp = temp->next;
			}

			// Create a new note and append it to the chain
			notes* item = new notes;
			item->title.push(title);
			item->content.push(cont);
			item->next = NULL;

			temp->next = item; // Link the new node to the chain
		}
	}


	void displayNotes()
	{
		for (int i = 0; i < tablesize; i++)
		{
			notes* temp = &table[i];

			if (!temp->content.empty())
			{

				while (temp != NULL)
				{
					// Display the content in the current node
					cout << " [";
					if (!temp->title.empty()) {
						cout << "Title: " << temp->title.top() << ", ";
					}
					cout << "Content: " << temp->content.top() << "]";
					temp = temp->next;
					if (temp != NULL) {
						cout << " -> ";
					}
				}

				cout << endl;
			}
		}
	}

	void updateNote(string title, string newContent)
	{
		int i = hash(title);
		notes* temp = &table[i];

		while (temp != NULL)
		{
			if (!temp->title.empty() && temp->title.top() == title)
			{ // Remove the old content
				temp->content.push(newContent); // Add the updated content
				cout << "Note with title '" << title << "' updated successfully." << endl;
				return;
			}
			temp = temp->next;
		}

		cout << "Note with title '" << title << "' not found." << endl;
	}
	void undoLastUpdate(string title)
	{
		int i = hash(title);
		notes* temp = &table[i];

		while (temp != NULL)
		{
			if (!temp->title.empty() && temp->title.top() == title)
			{
				if (temp->content.size() > 1)
				{
					temp->content.pop(); // Remove the last updated content
					cout << "Undo successful for note with title '" << title << "'." << endl;
				}
				else
				{
					cout << "No previous content to undo for note with title '" << title << "'." << endl;
				}
				return;
			}
			temp = temp->next;
		}

		cout << "Note with title '" << title << "' not found." << endl;
	}

};

int main()
{
	// Declare objects for Task Manager, Event Scheduler, and Note Scheduler
	TaskLinkedList taskManager;
	MinHeap eventScheduler; // Assuming MinHeap is defined for Event Scheduler
	NoteTaking Notetaking; // Assuming NoteTaking is defined for Note Scheduler

	int mainChoice;
	do {
		cout << "\nMain Menu:\n";
		cout << "1. Task Manager\n";
		cout << "2. Event Scheduler\n";
		cout << "3. Note Taking\n";
		cout << "4. Exit\n";
		cout << "Enter your choice: ";
		cin >> mainChoice;

		switch (mainChoice) {
		case 1: {
			int choice;
			do {
				cout << "\nTask Manager Menu:\n";
				cout << "1. Add Task\n";
				cout << "2. Remove Task\n";
				cout << "3. Search Task by Title\n";
				cout << "4. Search Tasks by Category\n";
				cout << "5. Display All Tasks\n";
				cout << "6. Exit\n";
				cout << "Enter your choice: ";
				cin >> choice;

				switch (choice) {
				case 1: {
					string title, category;
					int priority;
					cout << "Enter task title: ";
					cin.ignore();
					getline(cin, title);
					cout << "Enter task category: ";
					getline(cin, category);
					cout << "Enter task priority: ";
					cin >> priority;
					taskManager.addTask(title, category, priority);
					break;
				}
				case 2: {
					string title;
					cout << "Enter the title of the task to remove: ";
					cin.ignore();
					getline(cin, title);
					taskManager.removeTask(title);
					break;
				}
				case 3: {
					string title;
					cout << "Enter the title of the task to search: ";
					cin.ignore();
					getline(cin, title);
					taskManager.searchTaskTitle(title);
					break;
				}
				case 4: {
					string category;
					cout << "Enter the category to search tasks: ";
					cin.ignore();
					getline(cin, category);
					taskManager.searchTaskCategory(category);
					break;
				}
				case 5:
					taskManager.displayTasks();
					break;
				case 6:
					cout << "Exiting Task Manager...\n";
					break;
				default:
					cout << "Invalid choice. Please try again.\n";
				}
			} while (choice != 6);
			break;
		}
		case 2: {
			int choice;
			do {
				cout << "\nEvent Scheduler Menu:\n";
				cout << "1. Add Event\n";
				cout << "2. Remove Next Event\n";
				cout << "3. View Next Event\n";
				cout << "4. Display All Events\n";
				cout << "5. Exit\n";
				cout << "Enter your choice: ";
				cin >> choice;

				switch (choice) {
				case 1: {
					string title, description;
					int hour, minute;
					cout << "Enter event title: ";
					cin.ignore();
					getline(cin, title);
					cout << "Enter event time (hour 0-23): ";
					cin >> hour;
					cout << "Enter event time (minute 0-59): ";
					cin >> minute;
					cout << "Enter event description: ";
					cin.ignore();
					getline(cin, description);
					eventScheduler.addEvent(title, hour, minute, description);
					break;
				}
				case 2:
					eventScheduler.removeNextEvent();
					break;
				case 3:
					eventScheduler.viewNextEvent();
					break;
				case 4:
					eventScheduler.displayAllEvents();
					break;
				case 5:
					cout << "Exiting...\n";
					break;
				default:
					cout << "Invalid choice. Please try again.\n";
				}
			} while (choice != 5);
			break;
		}
		case 3: {
			int choice;
			do {
				cout << "\nNote Taking Menu:\n";
				cout << "1. Add Note\n";
				cout << "2. Update Note\n";
				cout << "3. Undo the last update for a note\n";
				cout << "4. Display all notes\n";
				cout << "5. Exit\n";
				cout << "Enter your choice: ";
				cin >> choice;

				switch (choice) {
				case 1: {
					string title, content;
					cout << "Enter note title: ";
					cin.ignore();
					getline(cin, title);
					cout << "Enter note content: ";
					getline(cin, content);
					Notetaking.addNote(title, content);
					break;
				}
				case 2: {
					string title, newContent;
					cout << "Enter the title of the note to update: ";
					cin.ignore();
					getline(cin, title);
					cout << "Enter the new content: ";
					getline(cin, newContent);
					Notetaking.updateNote(title, newContent);
					break;
				}
				case 3: {
					string title;
					cout << "Enter the title of the note to undo the last update: ";
					cin.ignore();
					getline(cin, title);
					Notetaking.undoLastUpdate(title);
					break;
				}
				case 4:
					Notetaking.displayNotes();
					break;
				case 5:
					cout << "Exiting Note Scheduler...\n";
					break;
				default:
					cout << "Invalid choice. Please try again.\n";
				}
			} while (choice != 5);
			break;
		}
		case 4:
			cout << "Exiting the program...\n";
			break;
		default:
			cout << "Invalid choice. Please try again.\n";
			break;
		}

	} while (mainChoice != 4);

	return 0;
}
