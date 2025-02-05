#include <bits/stdc++.h>
using namespace std;
class guess;

class random                                          // class random
{
private:
    int r;

public:
    random()                                          // generating a random number
    {
        srand(time(NULL));
        r = 1 + (rand() % 1000);
    }

    friend class guess;                               // friend class  
};

class guess                                           // class guess
{                                                       
    private:
    int input;                                                  
    int k;
    random *j= new random;                           // dynamic initialization   

    public:
    guess()                                             
    {
        input = 0;
        k = 0;
    }
    void guessing()                                                         // taking input from user
    {
        char ch;
        
        do
        {
            cout << "Guess the number between 1 and 1000!!!" << endl;
            cin >> input;
            k++;
            if (input < j->r)
                cout<< "Too low try again!!" << endl;
            else if (input > j->r)
                cout << "Too high try again!!" << endl;
            else{int cnt =0;
                cout << "Excellent you guessed the number would you like to play again!!" << endl;

                label:
                cout<<"press Y to try again and N to exit the game";
                cin>>ch;
                if (ch=='Y'||ch=='y'){
                    guessing();
                }
                else if (ch=='N'||ch=='n'){
                    exit(0);
                }
                else{ cout<<"enter a valid choice";
                count++;
                goto label;
                }
                
                if (count>=3){
                    cout<<"andha he kya bsdk🤬"<<endl; // win + ;😎
                    exit(0);
                }
            
            }
        } while (input != j->r);

        
        if (k < 10)
            cout << "Either you know the secret or you got lucky!!" << endl;
        else if (k == 10)
            cout << "haha you know the secret!!" << endl;
        
        else
        {
            try_again();
        }
    }
    
    void try_again()                                                                // to ask if user want to play again
    {
        int count = 0;
    to:

        cout << "you should be able to do better why should it take no more than 10 guesses!!" << endl;
        cout << "Do you want to try again ??\nEnter Y/N " << endl;
        char choice;
        cin >> choice;
        if (choice == 'Y' || choice == 'y')
        {
            k = 0;
            guessing();
        }
        else if (choice == 'N' || choice == 'n')
        {
            cout << "Do you want the  solution for the game Y/N" << endl;
            cin >> choice;
            if (choice == 'Y' || choice == 'y')
            {
                solution();
            }
            else if (choice == 'N' || choice == 'n')
            {
                cout << "Better luck next time!!" << endl;
                exit(0);
            }
        }
        else
        {
            cout << "You entered a wrong input" << endl;
            count++;
            if (count > 3)
            {
                cout << "Since Player is not entering right input." << endl;
                cout << "We are providing the solution " << endl;
                solution();
                exit(0);
            }
            goto to;
        }
    }
    
    
    void solution()                                                    // step by step solution to guess the number in 10 guesses
    {

        cout<<"Our number was "<<j->r;

        cout << " So the following steps should have been followed for the solution" << endl
             << endl;
        int low = 1, mid, high = 1000;
        int counter = 0;
        do
        {
            mid = (low + high) / 2;
            cout << "Take: " << mid << endl;
            if (mid == j->r)
            {
                break;
            }
            else if (mid < j->r)
            {
                cout << counter+1 << ".The number is too low so take a number between " << mid + 1 << " & " << high << endl;
                low = mid + 1;
            }
            else if (j->r < mid)
            {
                cout << counter+1 << ".The number is too high so take a number between " << high - 1 << " & " << mid << endl;
                high = mid - 1;
            }
            counter++;
        } while (mid != j->r);
        cout << "So we found " << mid << " in " << counter << " attempts :)" << endl;
    }

    ~guess()                                                // destructor
    {
        cout << "Game is Over" << endl;
    }
};

int main()
{
    // random guess;
    guess number;
    number.guessing();

    return 0;
}