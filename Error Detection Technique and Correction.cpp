#include<bits/stdc++.h>
#include <conio.h>
#include <windows.h>
using namespace std;

COORD coord = {0,0};

void gotoxy(int x,int y)
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}


void BitsStuffDestuff()
{
    int i, pos, k, c = 0, n, j;
    printf("Enter 0 or 1 as String: ");
    string s;
    cin >> s;
    cout << "\nAfter Bit Stuffing: \n";
    printf("01111110   ");
    int len = s.size();
    for (i = 0; i < len; i++) {

        if (s[i] == '1') {
            c++;
        } else {
            c = 0;
        }

        if (c == 5) {
            pos = i + 1;
            s.resize(len + 1);
            for (i = len; i > pos; i--) {
                s[i] = s[i - 1];
            }
            s[i] = '0';
            c = 0;
        }
    }

    cout << s;
    printf("   01111110");
    cout << "\n\nAfter Bit De-Stuffing: \n";

    c = 0;
    printf("01111110   ");
    for (i = 0; i < len; i++) {

        if (s[i] == '1') {
            c++;
        } else {
            c = 0;
        }

        if (c == 5) {
            pos = i + 1;
            for (i = pos; i < len; i++) {
                s[i] = s[i + 1];
            }
            s.resize(len);
        }
    }

    cout << s;
    printf("   01111110");
    cout<<endl;


    return;

    /**
Enter Any String: 10111111110101110

After Bit Stuffing:
01111110   101111101110101110   01111110

After Bit De-Stuffing:
01111110   10111111110101110   01111110

    */
}

void ByteStuffDestuff()
{
    cout<<"Enter String: ";
    vector<char>v;
    string s;
    cin>>s;
    char f,e;
    cout<<"Enter starting delimiter : ";
    cin>>f;
    cout<<"Enter  ending delimiter : ";
    cin>>e;
    v.push_back(f);
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]== e || s[i]==f)
        {
            v.push_back(e);
        }
        v.push_back(s[i]);
    }
    v.push_back(f);
    cout<<endl;
    cout<<"Data after stuffing: ";
    for(int i=0; i<v.size(); i++)
        cout<<v[i];
    cout<<endl;
    cout<<"Data after de stuffing: ";
    int c;
    c=0;
    for(int i=1; i<v.size()-1; i++)
    {
        if(v[i]==e && v[i+1]==f ||v[i]==e && v[i+1]==e)
        {
            continue;
        }
        else
        {
            cout<<v[i];
        }

    }
    cout<<endl<<endl;

    return;

    /**
    Enter String: shanto
    Flag: z
    ESC: q

    Data after stuffing: zshantoz
    Data after de stuffing: shanto

    */
}

void ParityCheck()
{
    string s;
    int n, C=0, C1=0;
    cout<< "Enter Data: ";
    cin>>s;
    cout<< "Choose Even(0)/Odd(1): ";
    cin>>n;

    int i, t;

    for(i=0; i<s.size(); i++)
    {
        if(s[i]=='1')
            C++;
    }

    if(C%2==0)
        t=0;
    else
        t=1;

    int len=s.size();
    if(t==n)
        s[len]='0';
    else
        s[len]='1';




   cout<< "Output(Data+Parity): ";
   for(i=0; i<=len; i++)
        cout<<s[i];
    cout<<endl;



    C=0;
    cout<< "Output(Data+Parity): ";
    for(i=0; i<=s.size(); i++)
    {
        cout<<s[i];
        if(s[i]=='1')
            C++;
    }
    cout<<endl;

    string s1;
    cout<<endl;
    cout<< "Input(Receiver Data): ";
    cin>>s1;
    for(i=0; i<s1.size(); i++)
    {
        if(s1[i]=='1')
            C1++;
    }
    if(C == C1)
        cout<< "No Error!"<<endl;
    else
        cout<< "Error!"<<endl;


    return;

    /**
    Enter Data: 100101001
    Choose Even(0)/Odd(1): 0
    Output(Data+Parity): 1001010010

    Input(Receiver Data): 1001010010
    No Error!
    */
}


void CRC()
{
    string crc, encoded = "", msg;
    cout << "Enter Sender Message: ";
    getline(cin, msg);
    cout << "Enter Polynomial: ";
    getline(cin, crc);
    int m = msg.length(), n = crc.length();
    encoded += msg;
    for (int i = 1; i <= n - 1; i++)
    {
        encoded += '0';
    }
    for (int i = 0; i <= encoded.length() - n;)
    {

        for (int j = 0; j < n; j++)
        {
            encoded[i + j] = encoded[i + j] == crc[j] ? '0' : '1';
        }
        while (i < encoded.length() && encoded[i] != '1')
        {
            i++;
        }
    }
    cout << "Final Sender Value: " << msg + encoded.substr(encoded.length() - n + 1) << endl;

    string crc1, decoded;
    cout << "Enter Receiver Message: ";
    getline(cin, decoded);
    cout << "Enter Polynomial: ";
    getline(cin, crc1);
    for (int i = 0; i <= decoded.length() - crc1.length();)
    {
        for (int j = 0; j < crc1.length(); j++)
        {
            decoded[i + j] = decoded[i + j] == crc1[j] ? '0' : '1';
        }
        while (i < decoded.length() && decoded[i] != '1')
        {
            i++;
        }
    }

    for (char i : decoded.substr(decoded.length() - crc1.length()))
    {
        if (i != '0')
        {
            cout << "Error in Communication!"<<endl<<endl;
            return ;
        }
    }
    cout << "No error!"<<endl<<endl;
    return;

    /**
    Enter sender message: 101101
    Enter polynomial: 1101
    Final Sender value: 101101,010
    Enter receiver Message: 101101010
    Enter polynomial: 1101
    No error
    */
}



void HummingCode()
{
    int a[7];
    cout<<"Enter 4 Bits of Data One by One"<<endl;
    cin>>a[0];
    cin>>a[1];
    cin>>a[2];
    cin>>a[4];
    a[3] = a[0]^a[1]^a[2];
    a[5] = a[0]^a[1]^a[4];
    a[6] = a[4]^a[2]^a[0];
    cout<<"Encoded Data is ";
    for(int i=0; i<7; i++)
    {
        cout<<a[i];
    }
    cout<<endl;
    cout<<"Enter Received Data Bits One by One"<<endl;
    int b[7];
    int k = 0;
    for(int i=0; i<7; i++)
    {
        cin>>b[i];
        if(a[i] != b[i]) k++;
    }
    if(k == 0) cout<<"No error!"<<endl;
    else
    {
        cout<<"Error!"<<endl;

        int  c1 = b[6]^b[4]^b[2]^b[0];
        int  c2 = b[5]^b[4]^b[1]^b[0];
        int  c4 = b[3]^b[2]^b[1]^b[0];
        int t = 0;
        if(c4 == 1) t = t+4;
        if(c2 == 1) t = t+2;
        if(c1 == 1) t = t+1;
        cout<<"Error at Position:"<<t<<endl;

        cout<<"Correct Data is: ";
        for(int i=0; i<7; i++)
        {
            cout<<a[i];
        }
    }
    cout<<endl<<endl;

    return;


    /**

Enter 4 Bits of Data One by One
1
0
1
0
Encoded Data is 1010010
Enter Received Data Bits One by One
1
0
1
0
0
1
0
No error!

    */
}

int main()
{
    char choice, another;

    while(true)
    {
        system("cls");

        gotoxy(29,05);
        printf("******* Welcome to our Project *******\n\n");
        printf("\t==========================================================================\n");
        printf("\t==================   Error-Detection and Correction    ===================\n");
        printf("\t==========================================================================\n\n");
        gotoxy(30,12);
        printf("1. Bit Stuffing and De-Stuffing");
        gotoxy(30,14);
        printf("2. Character Stuffing and De-Stuffing");
        gotoxy(30,16);
        printf("3. Parity Check");
        gotoxy(30,18);
        printf("4. Cyclic Redundancy Check");
        gotoxy(30,20);
        printf("5. Hamming Code");
        gotoxy(30,22);
        printf("6. Exit.Thank You");
        gotoxy(30,25);
        printf("Enter the operation you want to do: "); /// enter the choice 1, 2, 3, 4, 5
        fflush(stdin); /// flush the input buffer
        choice  = getche();

        switch(choice)
        {
        case '1':
            system("cls");

            another = 'y';
            while(another == 'y')
            {
                BitsStuffDestuff(); ///Bits Stuff and De Stuff
                printf("\nDo You Want To Use The Same Program? (y/n): ");
                fflush(stdin);
                another = getche();
                cout<<endl;
            }
            break;

        case '2':
            system("cls");

            another = 'y';
            while(another == 'y')
            {
                ByteStuffDestuff(); ///Bits Stuff and De Stuff
                printf("\nDo You Want To Use The Same Program? (y/n): ");
                fflush(stdin);
                another = getche();
                cout<<endl;
            }
            break;

        case '3':
            system("cls");

            another = 'y';
            while(another == 'y')
            {
                ParityCheck(); ///Bits Stuff and De Stuff
                printf("\nDo You Want To Use The Same Program? (y/n): ");
                fflush(stdin);
                another = getche();
                cout<<endl;
            }
            break;

        case '4':
            system("cls");

            another = 'y';
            while(another == 'y')
            {
                CRC(); ///Bits Stuff and De Stuff
                printf("\nDo You Want To Use The Same Program? (y/n): ");
                fflush(stdin);
                another = getche();
                cout<<endl;
            }
            break;

        case '5':
            system("cls");

            another = 'y';
            while(another == 'y')
            {
                HummingCode(); ///Bits Stuff and De Stuff
                printf("\nDo You Want To Use The Same Program? (y/n): ");
                fflush(stdin);
                another = getche();
                cout<<endl;
            }
            break;

        case '6':
            exit(0); /// exit from the program



        }

    }

    return 0;
}

