#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

class Message {
private:
    static unsigned int nextID;
    unsigned int id;
    string msg;
public:
    Message():msg("") {}
    Message(const string& s) :msg(s) { id = nextID++; }
    const string& get_text() {
        return msg;
    }
    friend bool operator<(const Message& lhs, const Message& rhs) {
        return (lhs.id < rhs.id) ? true : false;
    }
};

class MessageFactory {
public:
    MessageFactory() {}
    Message create_message(const string& text) {
        Message m = Message(text);
        return m;
    }
};
unsigned int Message::nextID = 0;

class Recipient {
private:
    void fix_order() {
        sort(messages_.begin(), messages_.end());
    }
    vector<Message> messages_;
public:
    Recipient() {}
    void receive(const Message& msg) {
        messages_.push_back(msg);
    }
    void print_messages() {
        fix_order();
        for (auto& msg : messages_) {
            cout << msg.get_text() << endl;
        }
        messages_.clear();
    }
};

class Network {
public:
    static void send_messages(vector<Message> messages, Recipient& recipient) {
        // simulates the unpredictable network, where sent messages might arrive in unspecified order
        random_shuffle(messages.begin(), messages.end());
        for (auto msg : messages) {
            recipient.receive(msg);
        }
    }
};



int main() {
    MessageFactory message_factory;
    Recipient recipient;
    vector<Message> messages;
    string text;
    while (getline(cin, text)) {
        messages.push_back(message_factory.create_message(text));
    }
    Network::send_messages(messages, recipient);
    recipient.print_messages();
}
