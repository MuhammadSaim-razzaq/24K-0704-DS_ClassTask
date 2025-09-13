#include <iostream>
#include <string>
using namespace std;

struct Node {
    string song;
    Node* next;
};

class Playlist {
    Node* last;
public:
    Playlist() { last = NULL; }

    void addSong(string s) {
        Node* n = new Node;
        n->song = s;
        if (!last) {
            n->next = n;
            last = n;
        } else {
            n->next = last->next;
            last->next = n;
            last = n;
        }
    }

    void showSongs() {
        if (!last) {
            cout << "Playlist is empty\n";
            return;
        }
        Node* t = last->next;
        cout << "Playlist:\n";
        do {
            cout << t->song << "\n";
            t = t->next;
        } while (t != last->next);
    }

    void playNext(string current) {
        if (!last) {
            cout << "Playlist is empty\n";
            return;
        }
        Node* t = last->next;
        do {
            if (t->song == current) {
                cout << "Now playing: " << t->next->song << "\n";
                return;
            }
            t = t->next;
        } while (t != last->next);
        cout << "Song not found\n";
    }

    void removeSong(string s) {
        if (!last) {
            cout << "Playlist is empty\n";
            return;
        }
        Node* cur = last->next;
        Node* prev = last;
        do {
            if (cur->song == s) {
                if (cur == last && cur == last->next) {
                    delete cur;
                    last = NULL;
                    return;
                }
                if (cur == last) last = prev;
                prev->next = cur->next;
                delete cur;
                return;
            }
            prev = cur;
            cur = cur->next;
        } while (cur != last->next);
        cout << "Song not found\n";
    }
};

int main() {
    Playlist p;
    int ch;
    string song;
    do {
        cout << "1. Add Song\n2. Show Playlist\n3. Play Next\n4. Remove Song\n5. Exit\n";
        cin >> ch;
        switch (ch) {
            case 1:
                cout << "Enter song name: ";
                cin.ignore();
                getline(cin, song);
                p.addSong(song);
                break;
            case 2:
                p.showSongs();
                break;
            case 3:
                cout << "Enter current song: ";
                cin.ignore();
                getline(cin, song);
                p.playNext(song);
                break;
            case 4:
                cout << "Enter song to remove: ";
                cin.ignore();
                getline(cin, song);
                p.removeSong(song);
                break;
        }
    } while (ch != 5);
}
