#include"calculate.h"
#include<QStack>
#include<QDebug>

bool isOperator(QChar ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

double performOperation(double num1, double num2, QChar op) {
    //使用 toLatin1() 将 QString op 转换为 QByteArray。
    switch (op.toLatin1()) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            return num1 / num2;
        default:
            return 0.0;
    }
}

QString Calculate::calculate(const QString& expression){
    QStack<double> numStack;
    QStack<QChar> opStack;

    for(int i=0;i<expression.length();++i){
        QChar ch=expression[i];
        //跳过间隔符
        if(ch.isSpace()){
            continue;
        }

        //拿数字
        if(ch.isDigit() || ch=='.'){
            int j=i;
            while(j < expression.length()&&(expression[j].isDigit()||expression[j]=='.')){
                ++j;
            }
            QString numberStr = expression.mid(i,j-i);
            //将一个字符串转换为双精度浮点数
            bool conversionSuccess = false;
            //如果转换成功，则 conversionSuccess 的值会被设置为 true
            double number = numberStr.toDouble(&conversionSuccess);
            if(conversionSuccess){
                numStack.push(number);
            }else{
                return "Error:Invalid number format";
            }
            i=j-1;
        }else if(isOperator(ch)){
            while(!opStack.isEmpty()&&isOperator(opStack.top())){
                QChar prevOp = opStack.top();
                opStack.pop();
                //没有足够的数字给符号做处理 Handle insufficient operands for an operator
                if(numStack.size()<2){
                    return "Error: Insufficient operands for operator";
                }
                double num2 = numStack.top();
                numStack.pop();
                double num1 = numStack.top();
                numStack.pop();
                double result = performOperation(num1,num2,prevOp);
                numStack.push(result);
            }
            opStack.push(ch);
        }else if(ch == '('){
            opStack.push(ch);
        }else if(ch == ')'){
            while (!opStack.isEmpty()&&opStack.top()!='('){
                QChar prevOp = opStack.top();
                opStack.pop();
                if(numStack.size()<2){
                    return "Error:Insufficient operands for operator";
                }
                double num2 = numStack.top();
                numStack.pop();
                double num1=numStack.top();
                numStack.pop();
                double result = performOperation(num1,num2,prevOp);
                numStack.push(result);
            }
            if(opStack.isEmpty()){
                return "Error: Mismatched parentheses";
            }
            opStack.pop();
        }else{
            return "Error: Invalid character in expression";
        }
    }

    while(!opStack.isEmpty()){
        QChar op = opStack.top();
        opStack.pop();
        if(numStack.size()<2){
            return "Error: Insufficient operands for operator";
        }
        double num2 = numStack.top();
        numStack.pop();
        double num1 = numStack.top();
        numStack.pop();
        double result = performOperation(num1,num2,op);
        numStack.push(result);
    }

    if(numStack.isEmpty()){
        return "Error: Empty expression";
    }else{
        double finalResult = numStack.top();
        return QString::number(finalResult);
    }
}
