#include "lectures.h"
#include <iostream>
#include <stack>
#include <string>

using namespace std;

/*
*  학습 목표 : 스택으로 후위 표기법 표현 및 계산 구현하기
*  
*  1. 표기법에 대해 이해
* 
*   1 + 1
*	연산자 (+,-,x,/) 피연산자
*	[전위 표기법] : 연산자의 위치가 앞에 있다.(ex) + 11
*	[중위 표기법] : 일반적으로 표기하는 방식. 연산자의 위치가 중간에 있다.
*	[후위 표기법] : 연산자의 위치가 뒤에있다. 11+
* 
*	중위 표기법을 사용 하는 이유 : 사람이 읽기 편해서 사용한다.
*	컴퓨터의 입장에서 중위 표기법의 단점 : 연산자의 우선 순위가 존재 하기 때문에 앞에서 부터 계산을 할 수 있다.
* 
*	11+ : 전위, 후위 표기법 방식을 사용하면, 앞에서 부터 정해진 규칙대로 수행하기만 하면 된다. 빠르다.
* 
*  2. 중위 표기법을 후위 표기법으로 바꾸는 방법
*   규칙1. 숫자는 그대로 출력한다.
*	규칙2. 스택이 비어있다면 연산자를 스택에 넣습니다.(push)
*	규칙3. 비교 | 스택의 최상단 (Top, peek)에 있는 연산자 < 현재 판단해야하는 연산자 : 현재 연산자를 스택에 넣습니다.
*	규칙4. 비교 | 스택의 최상단 (Top, peek)에 있는 연산자 >= 현재 판단해야하는 연산자 : 규칙2, 규칙3이 될 때 까지 출력하고 pop합니다.
*	규칙5. 수식이 끝난다면 스택이 빌 때까지 출력합니다. pop
*	규칙6. 여는 괄호 '('는 스택에 그냥 넣습니다. push
*	규칙7. 여는 괄호 바로 다음에 오는 연산자는 그냥 넣습니다. push
*	규칙8. 닫는 괄호 ')'여는 괄호가 stack에서 pop이 될 때까지 pop을 반복합니다. 
*  
*   예시)
*	데이터    : 1+2
*	규칙1 -> 규칙2 -> 규칙1 -> 규칙5
*	스택 공간 : [ + ] -> [ ]
*	출력 공간 : 12+
* 
*	먼저 계산해야하는 연산자가 우선순위가 높다. (숫자가 크다)	
* 
*	데이터 : 1+2x3
*	규칙1 -> 구칙2 -> 규칙1 -> 규칙3 -> 규칙1 -> 규칙5
*	스택 공간 : (bottom) [+,x] (top)
*	출력 공간 : 123x+
* 
*	데이터 : 1x2+3
*	규칙1 -> 규칙2 -> 규칙1 -> 규칙4 -> 규칙1
*	스택	 공간 :[x] -> [+]
*	출력 공간 : 1->12->12x->12x3->12x3+
* 
*	예제 문제
* 
*	데이터 : 1 + 2 x 3 + 4 / 5
*	1 > 2 > 1 > 3 > 1 > 4 > 1 > 3 > 1
*	스택 공간 : [+,x] > [+/] > []
*	출력 공간 : 123x+45/+ 
* 
*	데이터 : 1x(2+3)
* 	스택 공간 : x(+) 규칙8 (stack pop) 규칙5
*	출력 공간 : 123+x
* 
*	데이터 : (1+2)x(3+4)
*	스택 공간 : (+) > [ ] > [ x (+)]
*	출력 공간 : 12+34+x
* 
*	데이터 : (3+5x(4-6)/2)
*	스택 공간 : (+/
*	출력 공간 : 3546-x2/+
* 
*  3. 후위 표기법 계산 방법
*   
*	규칙1. 숫자는 스택에 추가합니다.
*	규칙2. 연산자가 나오면 스택에서 2개의 숫자를 pop해준다.
*	규칙3. 먼저 pop되는 숫자를 op2로 저장하고 나중에 pop되는 숫자를 op1로 저장한다.(op1 연산자 op2)로 결과값을 스택에 추가합니다.
*	규칙4. 스택의 마지막에 Top에 있는 결과값이 후위표기법의 계산 결과가 됩니다.
* 
*	1+2x3 = 7
*	123x+ = 7
*	스택공간 : [1,2,3] -> [1,6]
*	op1=2 x op2=3 = 6;
* 
*	3546-x2/+ 
*	-2 -10 -5 -2
*	
*/  

//	규칙1.숫자는 그대로 출력한다.
//	규칙2.스택이 비어있다면 연산자를 스택에 넣습니다.(push)
//	규칙3.비교 | 스택의 최상단(Top, peek)에 있는 연산자 < 현재 판단해야하는 연산자 : 현재 연산자를 스택에 넣습니다.
//	규칙4.비교 | 스택의 최상단(Top, peek)에 있는 연산자 >= 현재 판단해야하는 연산자 : 규칙2, 규칙3이 될 때 까지 출력하고 pop합니다.
//	규칙5.수식이 끝난다면 스택이 빌 때까지 출력합니다.pop
//	규칙6.여는 괄호 '('는 스택에 그냥 넣습니다.push
//	규칙7.여는 괄호 바로 다음에 오는 연산자는 그냥 넣습니다.push
//	규칙8.닫는 괄호 ')'여는 괄호가 stack에서 pop이 될 때까지 pop을 반복합니다.

// 중위 표기법 : (3 + 5x(4 - 6) / 2)
// 후위 표기법 : 3546 - *2 / +
 
// 중위 표기법을 후위 표기법으로 바꾸는 함수
// 후위 표기법을 계산하는 함수

// 스택 공간
// 출력 공간


/// <summary>
/// 우선순위는 리턴값이 클수록 높다
/// </summary>
int priority(char c) // '(' , ') , '+', '-', '*', '/'  // 곱하기== 나누기 > 더하기== 빼기> 여는 괄호 
{
	if (c == '(') // c가 괄호면 return 1
		return 1;
	else if (c=='+'||c=='-') // c가 +,-이면 return 2
		return 2;
	else if (c=='*'||c=='/') // c가 *,/이면 return 3
		return 3;
}


string ChangePostFix(string target)
{
	stack<char> stack; // 연산자를 저장할 스택 자료구조
	string prefix; // 결과(후위표기법)을 저장 할 변수

	// 연산자 
	// 피연산자 : 숫자는 prefix(출력 공간) 출력한다.

	for (int i = 0; i<target.length(); i++)
	{
		if (target[i] == '(') // 연산자와 괄호가 나왔을 때 처리하는 로직
			stack.push(target[i]); // 현재 연산자가 여는 괄호이면 스택에 추가한다.
		else if (target[i] == ')') // 닫는 괄호를 만난다면 s.top() '(' 만날때까지 pop해라
		{
			
			while (stack.top() != '(')
			{
				prefix += stack.top(); // 연산자는 결과에 따라 추가한다. <- 스택에서 출력해야 하기 때문에 stack.top으로 변경
				stack.pop();
			}
			stack.pop(); // '(' 괄호를 pop해서 스택에서 없앤다.
		}
		else if (target[i] == '+' || target[i] == '-' || target[i] == '*' || target[i] == '/')
		{
			while (!stack.empty() && priority(stack.top())>= priority(target[i])) // 규칙2또는 규칙3이 아닐 때
			{
				prefix += stack.top();
				stack.pop();
			}
			
			stack.push(target[i]);
		}
		else // 피연산자인 경우에 출력한다.
		{
			prefix += target[i];
		}
	}
	
	// 규칙 5.
	while (!stack.empty())
	{
		prefix += stack.top();
		stack.pop();
	}

	return prefix; 
}
//	규칙1.숫자는 스택에 추가합니다.
//	규칙2.연산자가 나오면 스택에서 2개의 숫자를 pop해준다.
//	규칙3.먼저 pop되는 숫자를 op2로 저장하고 나중에 pop되는 숫자를 op1로 저장한다.(op1 연산자 op2)로 결과값을 스택에 추가합니다.
//	규칙4.스택의 마지막에 Top에 있는 결과값이 후위표기법의 계산 결과가 됩니다.

int calcPostFix(string target)
{
	stack<int> s; // 수를 저장하는 자료구조

	for (int i = 0; i < target.length(); i++)
	{
		// 숫자면
		if (isdigit(target[i]))
		{
			int curNum = target[i] - '0';
			s.push(curNum); // char 데이터를 int 데이터로 
		}
		else // 연산자 일 때
		{
			int op2 = s.top();
			s.pop();
			int op1 = s.top();
			s.pop();

			switch (target[i])
			{
				case '+': s.push(op1 + op2); break;
				case '-': s.push(op1 - op2); break;
				case '*': s.push(op1 * op2); break;
				case '/': s.push(op1 / op2); break;
			}
		}
	}

	return s.top();
}


void lecture6()
{
	//string infix = "(3+5*(4-6)/2)";
	//
	//string postfix = ChangePostFix(infix);
	//
	//cout << "중위 표기식 : " << infix << endl;
	//cout << "후위 표기식 : " << postfix << endl;

	string fixed = "3546-*2/+";
	int last = calcPostFix(fixed);

	cout << fixed << endl;
	cout << last << endl;
}