#include<iostream>
#include<cstring>
using namespace std;

class UserAlreadyExistsException {
//TODO
private:
    char message[100];
public:
    UserAlreadyExistsException(char *message = "")
    {
        strcpy(this->message, message);
    }

    void print()
    {
        cout<<"User with username "<<message<<" already exsists!"<<endl;
    }
};

class UserNotFoundException {
//TODO
private:
    char message[100];
public:
    UserNotFoundException(char *message = "")
    {
        strcpy(this->message, message);
    }

    void print()
    {
        cout<<"User with username "<<message<<" was not found!"<<endl;
    }
};

class FriendsLimitExceededException {
//TODO
private:
    int number;
public:
    FriendsLimitExceededException(int number = 0)
    {
        this->number = number;
    }

    void print()
    {
        cout<<"Can't have more that "<<number<<" friends."<<endl;
    }
};

class User {
private:
    char username[50];
    int age;
    int friends;

public:
    static int limit;

    User(char *username = "", int age = 18) : age(age) {
        strcpy(this->username, username);
        friends = 0;
    }

    friend ostream &operator<<(ostream &os, const User &user) {
        os << "Username: " << user.username << " Age: " << user.age << " # of friends: " << user.friends;
        return os;
    }

    User &operator++() {
        ++friends;
        return *this;
    }

    static void setLimit(int a)
    {
        limit = a;
    }

    friend class SocialNetwork;


};

int User::limit=3;

class SocialNetwork {
private:
    User *users;
    int n;
public:
    SocialNetwork() {
        n = 0;
        users = new User[n];
    }

    SocialNetwork &operator+=(User &u) {

        User *tmp = new User[n + 1];
        for (int i = 0; i < n; i++) {
            tmp[i] = users[i];
        }
        tmp[n++] = u;
        delete[] users;
        users = tmp;
        return *this;
    }

    void friendRequest(char *firstUsername, char *secondUsername)
    {
        int flag1 = 0;
        int flag2 = 0;
        for (int i = 0; i < n; i++) {
            if (strcmp(users[i].username, firstUsername) == 0)
            {
                flag1 = 1;
                for (int j = 0; j < n; j++)
                {
                    if (strcmp(users[j].username, secondUsername) == 0)
                    {
                        flag2 = 1;
                        if(users[i].friends<User::limit && users[j].friends<User::limit)
                        {
                            ++users[i];
                            ++users[j];
                        }
                        else
                            throw FriendsLimitExceededException(User::limit);
                        return;
                    }
                }
            }
        }
        if(flag2==0)
        {
            throw UserNotFoundException(secondUsername);
        }
        else if(flag1==0)
        {
            throw UserNotFoundException(firstUsername);
        }
    }

    friend ostream &operator<<(ostream &os, const SocialNetwork &network) {
        os << "Users: " << endl;
        for (int i=0;i<network.n;i++) {
            os << network. users[i] << endl;
        }
        return os;
    }
};


int main() {
    SocialNetwork sn;
    int n;
    cin >> n;
    for (int i=0;i<n;i++){
        char username[50]; int age;
        cin >> username >> age;
        try
        {
            User u(username, age);
            sn+=u;
        }
        catch (UserAlreadyExistsException e)
        {
            e.print();
        }
    }

    cout << "Registration of users " << endl;
    cout << sn << endl;
    cout << "Friend requests " << endl;

    int friendships;
    cin >> friendships;
    for (int i=0;i<friendships;i++){
        char username1[50], username2[50];
        cin >> username1 >> username2;
        try
        {
            sn.friendRequest(username1, username2);
        }
        catch(UserNotFoundException e)
        {
            e.print();
        }
        catch(FriendsLimitExceededException e)
        {
            e.print();
        }
    }
    cout << sn << endl;
    cout << "CHANGE STATIC VALUE" << endl;
    int maxFriends;
    cin >> maxFriends;
    cin >> friendships;
    User::setLimit(maxFriends);
    for (int i=0;i<friendships;i++)
    {
        char username1[50], username2[50];
        cin >> username1 >> username2;
        try
        {
            sn.friendRequest(username1, username2);
        }
        catch (UserNotFoundException e)
        {
            e.print();
        }
        catch (FriendsLimitExceededException e)
        {
            e.print();
        }
    }
    cout << sn;
    return 0;
}