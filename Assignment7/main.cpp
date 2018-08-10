//
//  main.cpp
//  Assignment7
//  This assignment is intended write some functions without using
//  C-string library functions. Instead write my own.
//  Created by Sukhrobjon Golibboev on 3/12/18.
//  Copyright © 2018 Sukhrobjon Golibboev. All rights reserved.
//

#include <iostream>
using namespace std;
const int MAX_NUMBER = 128;

int lastIndexOf(char *, char);
void reverse (char *);
int replace(char *, char, char);
int findSubstring (char *, char []);
bool isPalindrome(char *);
void reverseWords(char *);
void swapper (char &, char&);
int stringLength(char *);

int main()
{
    // last index function test
    char s[MAX_NUMBER] = "between";
    char target = 'e';
    char target2 = 'l';
    cout << "The word is " << s <<  endl;
    cout << "The last index of '" << target << "' is: "<<lastIndexOf(s, target) << endl;
    cout << "The last index of '" << target2 << "' is: "<<lastIndexOf(s, target2) << endl;
    
    // reverse() function test
    char s2[MAX_NUMBER] = "flower!";
    cout << "Before reverse order function called: " << s2 << endl;
    reverse(s2);
    cout << "After reverse order function called: " << s2 << endl;

    // replace() function test
    char replaceChar = 'G';
    char target1 = 'g';
    char s3[MAX_NUMBER] = "go giants";
    int numOfRep = replace(s3, target1, replaceChar);
    cout <<"Num of replacement of " << target1 << " is " << numOfRep << endl;
    cout << "And now the word is after recplace function called : " << s3 << endl;

    // findSubstring() function test
    char s4[MAX_NUMBER] = "Skyscraper";
    char substring[MAX_NUMBER] = "ysc";
    cout << substring << " of " << s4 << " occures in the index of: ";
    cout << findSubstring(s4, substring) << endl;

    // isPalindrome() function test
    char palTest[MAX_NUMBER] = "abc cba";
    char palTest1[MAX_NUMBER] = "abc ba";
    if(isPalindrome(palTest))
        cout << palTest << " is a palindrome.\n";
    else
        cout << palTest << " is NOT a palindrome.\n";
    
    if(isPalindrome(palTest1))
        cout << palTest1 << " is a palindrome.\n";
    else
        cout << palTest1 << " is NOT a palindrome.\n";

    // extra credit part reverseWords() function test
    char s5[MAX_NUMBER] = "The Giants won the Pennant!";
    cout << "The string is before reverseWords() called was: " << s5 << endl;
    reverseWords(s5);
    cout << "The string is after reverseWords() called was: " << s5 << endl;
    

    return 0;
}

/*
 *  This function returns the last index where the target
 *  char can be found in the string. It returns -1 if the
 *  target char does not appear in the string.
 */
int lastIndexOf(char *s, char target) {
    
    int i = 0;
    int lastIndex = -1;
    while(s[i] != '\0') {
        if (s[i] == target) {
            lastIndex = i;
            i++;
        } else {
            i++;
        }
    }
    return lastIndex;
}

/*
 *  This function reverses the string.
 */
void reverse(char *s) {
    
    int len = stringLength(s);
    int k = 0;
    while (len > k)
    {
        swapper(s[k++], s[(len--) - 1]);
    }
}

/*
 *  This function finds all instances of the char ‘target’ in the
 *  string and replaces them with ‘replacementChar’.  It also returns
 *  the number of replacements that it makes.
 */
int replace (char *s, char target, char replaceChar){
    int count = 0;
    int i = 0;
    while(s[i] != '\0') {
        if(s[i] == target){
            s[i] = replaceChar;
            count++;
        }
        i++;
    }
    return  count;
}
/*
 *  This function returns the index in string s where the substring can first be found.
 */
int findSubstring(char *s, char substring[]){
    int index = -1;
    int i = 0;
    int j = 0;
    int num = lastIndexOf(s, substring[j]);
    if(num !=-1){
        i=num;
        while(substring[j] != '\0'){
            if(s[i] == substring[j]){
                index = num;
                j++;
                i++;
            }else {
                index = -1;
                break;
            }
        }
    }
    return index;
}
/*
 *  This function returns true if the argument string is a palindrome.
 *  It returns false if it is not.  A palindrome is a string that is
 *  spelled the same as its reverse.
 */
bool isPalindrome(char *s) {
    bool palindrome = false;
    int length = stringLength(s);
    for(int i=0; i < (length/2); i++){
        if(s[i] == s[length-1-i])
            palindrome = true;
        else {
            palindrome = false;
            break;
        }
    }
    return palindrome;
}

void reverseWords(char *s) {
    
    reverse(s);
    
    int i = 0;
    int k = 0;
    int len;
    while (s[i]) {
        if (s[i] == ' ') {
            len = i;
            while (len > k) {
                swapper(s[k++], s[--len]);
            }
            k = i + 1;
        }
        i++;
    }
    
    while (i > k) {
        swapper(s[k++], s[--i]);
    }
}

void swapper (char &x, char &y){
    
    char temp = x;
    x = y;
    y = temp;
    
}

// This function returs the length of the string
int stringLength(char *s) {
    int i=0;
    while(s[i++]);
    return --i;
}
/*
 Sample Output:
 
 The word is between
 The last index of 'e' is: 5
 The last index of 'l' is: -1
 Before reverse order function called: flower!
 After reverse order function called: !rewolf
 Num of replacement of g is 2
 And now the word is after recplace function called : Go Giants
 ysc of Skyscraper occures in the index of: 2
 abc cba is a palindrome.
 abc ba is NOT a palindrome.
 The string is before reverseWords() called was: The Giants won the Pennant!
 The string is after reverseWords() called was: Pennant! the won Giants The
 Program ended with exit code: 0
 */
