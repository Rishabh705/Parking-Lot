#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <cctype>
#include <bits/stdc++.h>
using namespace std;
int j = 0;
vector<vector<string>> slots;
string colour[10] = {"red", "blue", "yellow", "green", "silver", "black", "white", "grey", "orange", "purple"};
string lower(string str1)
{
    for (int i = 0; i < str1.length(); i++)
        str1[i] = tolower(str1[i]);
    return str1;
}
int countWords(string line)
{
    stringstream stream(line);
    return distance(istream_iterator<string>(stream), istream_iterator<string>());
}
class Valid
{
protected:
    bool checkNumber(string reg)
    {
        if (reg.length() != 9)
            return false;
        if (isdigit(reg[0]) && isdigit(reg[1]) && isdigit(reg[4]) && isalpha(reg[2]) && isalpha(reg[3]) && isalpha(reg[5]) && isalpha(reg[6]) && isalpha(reg[7]) && isalpha(reg[8]))
            return false;
        return true;
    }
    bool checkColour(string clr)
    {
        for (size_t i = 0; i < 12; i++)
            if (((lower(clr).compare(lower(colour[i]))) == 0 | lower(clr).compare(lower(colour[i])) == 0))
                return true;
        return false;
    }
};
class ParkingEntry : Valid
{
    vector<int> empty_slots;

public:
    ParkingEntry(int n = 10)
    {
        for (size_t i = 0; i < n; i++)
            empty_slots.push_back(i); // as initially all slots are empty.
        for (int i = 0; i < 3; i++)
            slots.push_back(vector<string>()); // Add an empty row
    }
    bool exists(string reg)
    {
        for (size_t i = 0; i < slots[1].size(); i++)
        {
            if (reg.compare(slots[1][i]) == 0)
                return true;
        }
        return false;
    }
    void park(string n, string clr, int l) // park car of particular color = clr  and number = n at nearest slot.
    {
        if (checkNumber(n) && checkColour(clr))
        {
            if (!exists(n))
            {
                if (j < l)
                {
                    int nearest = *min_element(empty_slots.begin(), empty_slots.end()); // nearest available slot obtained
                    slots[0].push_back(clr);
                    slots[1].push_back(n);
                    slots[2].push_back(to_string(nearest));
                    auto it = find(empty_slots.begin(), empty_slots.end(), nearest);
                    int index = it - empty_slots.begin();
                    empty_slots.erase(empty_slots.begin() + index);
                    cout << "Your car " << n << " is parked at slot number " << nearest + 1 << endl;
                    j++;
                }
                else
                    cout << "Sorry...Parking Lot is full!\n";
            }
            else
                cout << "Car " << n << " already parked.\n";
        }
        else
            cout << "Incorrect data!!\n";
    }
    void unpark(string n)
    {
        bool car_was_present = false;
        int i;
        for (i = 0; i < j; i++)
        {
            if (n.compare(slots[1][i]) == 0)
            {
                slots[0].erase(slots[0].begin() + i);
                slots[1].erase(slots[1].begin() + i);
                slots[2].erase(slots[2].begin() + i);
                cout << "Your car " << n << " is unparked!\n";
                car_was_present = true;
                j--;
                break;
            }
        }
        if (car_was_present)
            empty_slots.push_back(i);
        else
            cout << "Oops!..No such car present.\n";
    }
};
class Details : Valid
{
public:
    void findCar(string reg, int slot_number, bool flag)
    {
        bool found = false;
        for (size_t i = 0; i < j; i++)
        {
            if (flag == true)
            {
                if (reg.compare(slots[1][i]) == 0)
                {
                    cout << "Car number " << reg << " : " << endl;
                    cout << "Colour of " << slots[1][i] << " is : " << slots[0][i] << endl;
                    cout << "Slot number of " << slots[1][i] << " is : " << stoi(slots[2][i]) + 1 << endl;
                    found = true;
                    break;
                }
            }
            else
            {
                if (to_string(slot_number - 1).compare(slots[2][i]) == 0)
                {
                    cout << "Slot " << slot_number << " : " << endl;
                    cout << "Car number is : " << slots[1][i] << endl;
                    cout << "Colour of " << slots[1][i] << " is : " << slots[0][i] << endl;
                    found = true;
                    break;
                }
            }
        }
        if (found == false)
            cout << "Oops!..No data found.\n";
    }
    void findByClr(string clr)
    {
        bool found = false;
        bool check = checkColour(clr);
        if (check)
        {
            cout << "Registration number\t\tSlot\n";
            for (size_t i = 0; i < j; i++)
            {
                if (clr.compare(slots[0][i]) == 0)
                {
                    cout << "   " << slots[1][i] << "\t\t\t  " << stoi(slots[2][i]) + 1 << "\n";
                    found = true;
                }
            }
        }
        if (found == false)
            cout << "Oops!..No data found.\n";
    }
};
int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        fstream fio;
        string word;
        fio.open(argv[1], ios::in);
        string reg, clr, temp;
        fio >> word;
        if (word.compare("create_parking_lot") == 0)
        {
            fio >> word;
            int n = stoi(word);
            ParkingEntry obj(n);
            Details ob;
            while (fio >> word)
            {
                if (word.compare("park") == 0)
                {
                    getline(fio, temp);
                    if (countWords(temp) == 2)
                    {
                        istringstream ss(temp);
                        ss >> reg;
                        ss >> clr;
                        obj.park(reg, clr, n);
                    }
                    else
                        cout << "Insufficient data!!\n";
                }
                else if (word.compare("unpark") == 0)
                {
                    getline(fio, temp);
                    if (countWords(temp) == 1)
                    {
                        istringstream ss(temp);
                        ss >> reg;
                        obj.unpark(reg);
                    }
                    else
                        cout << "Insufficient data!!\n";
                }
                else if (word.compare("find_parking_slot") == 0)
                {
                    getline(fio, temp);
                    if (countWords(temp) == 1)
                    {
                        istringstream ss(temp);
                        ss >> temp;
                        ob.findCar("", stoi(temp), false);
                    }
                    else
                        cout << "Insufficient data!!\n";
                }
                else if (word.compare("find_car_number") == 0)
                {
                    getline(fio, temp);
                    if (countWords(temp) == 1)
                    {
                        istringstream ss(temp);
                        ss >> reg;
                        ob.findCar(reg, 0, true);
                    }
                    else
                        cout << "Insufficient data!!\n";
                }
                else if (word.compare("find_car") == 0)
                {
                    getline(fio, temp);
                    if (countWords(temp) == 1)
                    {
                        istringstream ss(temp);
                        ss >> clr;
                        ob.findByClr(clr);
                    }
                    else
                        cout << "Insufficient data!!\n";
                }
                else
                    cout << "Invalid input.\n";
            }
        }
        else
            cout << "Error : Wrong command.\n";
    }
    else
    {
        string line, word, reg, clr;
        cout << "Create parking lot or type 'quit' to exit\n";
        getline(cin, line);
        stringstream iss(line);
        iss >> word;
        if (word.compare("create_parking_lot") == 0)
        {
            cout << "Parking lot created.\n";
            iss >> word;
            int n = stoi(word);
            ParkingEntry obj(n);
            Details ob;
            while (1)
            {
                cout << "\nEnter command or type 'quit' to exit\n";
                getline(cin, line);
                stringstream iss(line);
                iss >> word;
                if (word.compare("park") == 0 && countWords(line)==3)
                {
                    iss >> reg;
                    iss >> clr;
                    obj.park(reg, clr, n);
                }
                else if (word.compare("unpark") == 0)
                {
                    iss >> reg;
                    obj.unpark(reg);
                }
                else if (word.compare("find_parking_slot") == 0)
                {
                    iss >> reg;
                    ob.findCar("", stoi(reg), false);
                }
                else if (word.compare("find_car_number") == 0)
                {
                    iss >> reg;
                    ob.findCar(reg, 0, true);
                }
                else if (word.compare("find_car") == 0)
                {
                    iss >> clr;
                    ob.findByClr(clr);
                }
                else if (lower(word).compare("quit") == 0)
                {
                    cout << "Exiting...\n";
                    break;
                }
                else
                    cout << "Error : Inappropriate command\n";
            }
        }
        else if (lower(word).compare("quit") == 0)
            cout << "Thank you\n";
        else
            cout << "Error : Inappropriate command or Parking Lot not created\n";
    }
    return 0;
}