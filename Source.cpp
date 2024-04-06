#include <iostream>
#include<fstream>
#include<string>
using namespace std;

template<class T>
class LinkedList {
	struct Node {
	public:
		T song_id;
		T song_name;
		T Lyricist;
		T Singer;
		T Duration;
		Node* next;
	
		Node() {
			song_id = " ";
			song_name = " ";
			Lyricist = " ";
			Singer = " ";
			Duration = " ";
		}
		Node(T const s_id, T const s_name, T const Lyist, T const sng, T const dur) {
			song_id = s_id;
			song_name = s_name;
			Lyricist = Lyist;
			Singer = sng;
			Duration = dur;
		}
	};
	Node* head;
	Node* tail;
public:
	LinkedList() {
		head = nullptr;
		tail = nullptr;
	}
	Node* createNode(T const s_id, T const s_name, T const Lyist, T const sng, T const dur) {
		Node* temp = new Node();
		temp->song_id = s_id;
		temp->song_name = s_name;
		temp->Lyricist = Lyist;
		temp->Singer = sng;
		temp->Duration = dur;
		temp->next = nullptr;
		return temp;
	}
	void insertAtHead(T const song_id, T const song_name, T const Lyricist, T const singer, T const duration) {
		if (head == nullptr){
			head = createNode(song_id, song_name, Lyricist, singer, duration);
			tail = head;
	    }
		else {
			Node* temp = createNode(song_id, song_name, Lyricist, singer, duration);
			temp->next = head;
			head = temp;
		}
	}
	void insertAtTail(T const song_id, T const song_name, T const Lyricist, T const singer, T const duration) {
		if (head == nullptr) {
			head = createNode(song_id, song_name, Lyricist, singer, duration);
			tail = head;
		}
		else {
			tail->next = createNode(song_id, song_name, Lyricist, singer, duration);
			tail = tail->next;
		}

	}
	void print() const {
		Node* ptr = head;
		while (ptr->next != tail) {
			cout << "Song ID  : " << ptr->song_id << "         " << "Song Name : " << ptr->song_name << "         "
				<< "Lyricist : " << ptr->Lyricist << "         " << "Singer : " << ptr->Singer << "         "
				<< "Duration : " << ptr->Duration << endl;
			ptr = ptr->next;
		}
	} 
	void eraseAtHead() {
		if (head) {
			Node* temp = head;
			head = head->next;
			delete temp;
		}
	}
	void eraseAtTail() {
		T data = tail->data;
		delete tail;
		Node* ptr = head;
		while (ptr->next) {
			ptr = ptr->next;
		}
		tail = ptr;
	}
	~LinkedList() {
		cout << "" << endl << endl;
	}
};



int main()
{
	LinkedList<int> l1;
	l1.insertAtHead(5, 6, 7, 8, 9);
	l1.insertAtTail(2, 3, 4, 5, 6);
	l1.print();

	fstream file;
	file.open("songlist.csv");
	if (!file)
	{
		cout << "file not opened";
	}
	else
	{
		string s = "";
		while (file.good())
		{
			getline(file, s);
			cout << s << endl;
			int len = s.size();
			cout << "len" << len << endl;
		}
	}
	LinkedList <string> one;
	one.insertAtHead("2", "Yaaro Mera Yaar Na Raha", "sahir ali bagga", "sahir ali bagga", "5");
	//one.print();
	one.insertAtHead("6", "Watan Ka Ishq", "sahir ali bagga", "sahir ali bagga", "4");
	// one.print();
	one.insertAtHead("7", "Junoon sy aur ishq sy", "ali azmat", "samina Ahmad", "4");
	one.print();
	one.insertAtTail("3", "Tu Jhoom", "Adnan Dhool", "Naseebo lab", "8");
	// one.print();
	one.insertAtTail("8", "Meray Watan Ye Aqeedatien", "hammad ali shah", "sahir ali bagga", "4");
	// one.print();
	one.insertAtTail("1", "Paighaam Layi Saba", "Masood Alam", "atif aslam", "5");
	one.print();

	return 0;
}
