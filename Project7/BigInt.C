#include"BigInt.h"
#include<iostream>
#include<cstring>
using namespace std;

BigInt::BigInt(int Number)
{
	if (Number == 0)
	{
		isZero = true;
		size = 1;
		s = new char[2];
		s[0] = '0';
		s[1] = '\0';
		isMinus = false;
	}
	else
	{
		if(Number < 0)
		{
			isMinus = true;
		}
		else
		{
			isMinus = false;
			Number = 0-Number;
		}
		isZero = false;
		size_t n = Number, digit;
		size = 0;
		len = 0;
		while(Number != 0)
		{
			size++;
			Number /= 10;
		}
		s = new char[size + 1];
		for (int i = size - 1; i >= 0; i--)
		{
			digit = n % 10;
			s[i] = '0' + digit;
			n /= 10;
		}
		s[size] = '\0';
	}
}

BigInt::BigInt()
{
	isMinus = false;
	size = 0;
	s = new char[0];
	isZero = true;
}

BigInt::BigInt(const char* other)
{
	if(other[0] == 45)
	{
		isMinus = true;
		isZero = false;
		size = strlen(other) - 1;
		s = new char[size + 1];
		int j = 1;
		for (int i = 0; i < size; i++)
		{
			s[i] = other[j];
			j++;
		}
		s[size] = '\0';
	}
	else if(other[0] == 48)
	{
		isZero = true;
		isMinus = false;
		size = 1;
		s = new char[size + 1];
		s[0] = '0';
		s[1] = '\0';
	}
	else
	{
		isMinus = false;
		size = strlen(other);
		s = new char[size + 1];
		s[size] = '\0';
		strcpy(s, other);
		if (size == 1 && s[0] == '0')
		{
			isZero = true;
		}
		else
		{
			isZero = false;
		}
	}
}

BigInt::~BigInt()
{
	delete[] s;
}

BigInt::BigInt(const BigInt& other)
{
	size = other.size;
	isZero = other.isZero;
	isMinus = other.isMinus;
	s = new char[size + 1];
	for (int i = 0; i < size; i++)
	{
		s[i] = other.s[i];
	}
	s[size] = '\0';
}

BigInt& BigInt::operator=(const BigInt& other)
{
	if(this == &other)
	{
		return *this;
	}
	size = other.size;
	isMinus = other.isMinus;
	isZero = other.isZero;
	delete[] s;
	s = new char[size + 1];
        for (int i = 0; i < size; i++)
        {
                s[i] = other.s[i];
        }
        s[size] = '\0';
	return *this;
}

int BigInt::compare(const BigInt& a, const BigInt& b)
{
	if(a.isMinus == true && b.isMinus ==false)
	{
		return -1;
	}
	else if(a.isMinus == false && b.isMinus == true)
	{
		return 1;
	}
	else if(a.isMinus == true && b.isMinus ==true)
	{
		int cmp = cmpAbsolute(&a, &b);
		if(cmp > 0)
		{
			return -1;
		}
		else if(cmp == 0)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	else
	{
		return cmpAbsolute(&a, &b);
	}
}

int BigInt::operator==(const BigInt& other)
{
	bool isDif = compare(other, *this);
	if(isDif == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int BigInt::operator>=(const BigInt& other)
{
	int judge = compare(*this, other);
	if (judge == -1)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int BigInt::operator<=(const BigInt& other)
{
        int judge = compare(*this, other);
        if (judge == 1)
        {
                return 0;
        }
        else
        {
                return 1;
        }
}

int BigInt::operator>(const BigInt& other)
{
	int judge = compare(*this, other);
	if (judge == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int BigInt::operator<(const BigInt& other)
{
        int judge = compare(*this, other);
        if (judge == -1)
        {
                return 1;
        }
        else
        {
                return 0;
        }
}

int BigInt::operator!=(const BigInt& other)
{
        int judge = compare(*this, other);
        if (judge == 0)
        {
                return 0;
        }
        else
        {
                return 1;
        }
}

ostream& operator<<(ostream& os,const BigInt& other)
{
	if(other.isMinus == true)
	{
		os << '-';
	}
	for (int i = 0; i < other.size; i++)
	{
		os << other.s[i];
	}
	return os;
}

int BigInt::cmpAbsolute(const BigInt* b1,const BigInt* b2)
{
	if ( b1->size != b2->size)
	{
		if(b1->size > b2->size)
		{
			return 1;
		}
		else
		{
			return -1;
		}
	}
	else if(b1->isZero == true && b2->isZero == true)
	{
		return 0;
	}
	else
	{
		return strcmp(b1->s, b2->s);
	}
}

BigInt& BigInt::operator+=(const BigInt& other)
{
	if(this->isZero == true)
	{
		*this = other;
		return *this;
	}
	else if(other.isZero == true)
	{
		return *this;
	}
	else
	{
		*this = *this + other;
		return *this;
	}
}

BigInt BigInt::operator+(const BigInt& other)
{
	BigInt tmp;
	if(this->isMinus != other.isMinus)
	{
		tmp = pureSub(*this, other);
		if(isMinus == true && tmp.isZero == false)
		{
			tmp.isMinus = !tmp.isMinus;
		}
		return tmp;
	}
	else
	{
		tmp = pureSum(*this, other);
	}
	return tmp;
}

BigInt& BigInt::operator*=(const BigInt& other)
{
        if(this->isZero == true || other.isZero == true)
        {
                return *this;
        }
        else
        {
                *this = *this * other;
                return *this;
        }
}

BigInt BigInt::operator*(const BigInt& other)
{
	if (this->isZero ==true || other.isZero ==true)
	{
		size_t zero = 0;
		BigInt tmp0(zero);
		return tmp0;
	}
        const BigInt* pb;  //指向位数多的数的指针
        const BigInt* ps;  //指向位数少的数的指针
        BigInt* tmp;  //BigInt数组，用于存储每一位与乘数的积
        BigInt finalSum;//tmp数组的总和
        if(this->size >= other.size)
        {
                pb = this;
                ps = &other;
        }
        else
        {
                pb = &other;
                ps = this;
        }
        tmp = new BigInt[pb->size];
        int t = 0; //t用于计量用到了第几个tmp
        for (int i = ps->size - 1; i >= 0; i--)  //循环较小的那个数，每次拿出一位与大的那个数乘起来
        {
        	tmp[i].isMinus = false;
        	int len = pb->size + 1 + t; //len表示某一位相乘之后实际的长度
        	int sum[len], carry = 0;
        	bool isBigger = false;
        	int k = 0; //k用于计量用到了第几个sum了，也就是到第几位了
        	for (int j = pb->size - 1; j >= 0; j--) //循环较大的那个数，每次拿出一位与当前较小的数拿出的位相乘
        	{
       	                sum[k] = (pb->s[j] - '0') * (ps->s[i] - '0') + carry;
	                if(sum[k] >= 10)
	                {
	                        carry = sum[k] / 10;
	                        sum[k] %= 10;
	                }
	                else
	                {
	                        carry = 0;
	                }
	                //if(sum[k] < 0 || sum[k] >= 10)
	                //{
	                        //cout <<"WRONG!" <<endl;
	                //}
		        k++;
        	}
	        if(carry != 0)
	        {
	                sum[pb->size] = carry;
	                delete[] tmp[t].s;
	                tmp[t].s = new char[pb->size + ps->size +1];
	                tmp[t].size = pb->size + 1;
	        }
	        else
	        {
	                delete[] tmp[t].s;
	                tmp[t].s = new char[pb->size + ps->size +1];
	                tmp[t].size = pb -> size;
	        }
	        int tmp_i = 0;
	        for (int i = tmp[t].size - 1; i >= 0; i--)
	        {
	                tmp[t].s[tmp_i] = sum[i] + '0';
	                tmp_i++;
	                tmp[t].whetherZero();
	        }
	        for (int i = tmp[t].size; i < len; i++)
	        {
	        	tmp[t].s[i] = '0';
	        }
	        tmp[t].size += t;
	        tmp[t].s[tmp[t].size] = '\0';
		t++;
        }
        for (int i = 0; i < pb->size; i++)
        {
        	finalSum += tmp[i];
        	finalSum.whetherZero();
        }
        delete[] tmp;
        if(pb->isMinus == ps->isMinus)
        {
        	finalSum.isMinus = false;
        }
        else
        {
        	finalSum.isMinus = true;
        }
        return finalSum;
}

void BigInt::whetherZero()
{
	for (int i = 0; i < size; i++)
	{
		if(s[i] != '0')
		{
			isZero = false;
			return;
		}
	}
	isZero = true;
}

BigInt BigInt::pureSum(const BigInt& a, const BigInt& b)
{
	BigInt tmp;
	const BigInt* pb;
	const BigInt* ps;
	int judge = cmpAbsolute(&a, &b);
	if(judge > 0)
	{
		pb = &a;
		ps = &b;
	}
	else
	{
		pb = &b;
		ps = &a;
	}
	int sum[pb->size + 1], carry = 0;
	bool isBigger = false;
	int j = pb->size - 1, k = 0;
	for (int i = ps->size - 1; i >= 0; i--)
	{
		sum[k] = pb->s[j] + ps->s[i] - 96 + carry;
		if(sum[k] >= 10)
		{
			carry = 1;
			sum[k] -= 10;
		}
		else
		{
			carry = 0;
		}
		if(sum[k] < 0 || sum[k] >= 10)
		{
			cout <<"WRONG!" <<endl;
		}
		k++;
		j--;
	}
	for (int i = pb->size - ps->size - 1; i >= 0; i--)
	{
		sum[k] = pb->s[i] - '0' + carry;
		if(sum[k] >= 10)
		{
			carry = 1;
			sum[k] -= 10;
		}
		else
		{
			carry = 0;
		}
		k++;
	}
	if(carry == 1)
	{
		sum[pb->size] = 1;
		delete[] tmp.s;
		tmp.s = new char[pb->size + 1];
		tmp.size = pb->size + 1;
	}
	else
	{
		delete[] tmp.s;
		tmp.s = new char[pb->size];
		tmp.size = pb -> size;
	}
	j = 0;
	for (int i = tmp.size - 1; i >= 0; i--)
	{
		tmp.s[j] = sum[i] + '0';
		j++;
	}
	tmp.isMinus = false;
	return tmp;
}

BigInt BigInt::pureSub(const BigInt& a, const BigInt& b)
{
	const BigInt* pb;
	const BigInt* ps;
	BigInt result;
	int judge = cmpAbsolute(&a, &b);
	if(judge > 0)
	{
		result.isMinus = false;
		result.isZero = false;
		pb = &a;
		ps = &b;
	}
	else if(judge == 0)
	{
		result.isZero = true;
		result.isMinus = false;
		delete[] result.s;
		result.size = 1;
		result.s = new char[2];
		result.s[0] = '0';
		result.s[1] = '\0';
		return result;
	}
	else
	{
		result.isZero = false;
		result.isMinus = true;
		pb = &b;
		ps = &a;
	}
	int carry = 0, k = 0, tmp_i = pb->size - 1;
	delete[] result.s;
	result.s = new char[pb->size + 1];
	for (int i = ps->size - 1; i >= 0; i--)
	{
		if(pb->s[tmp_i] > ps->s[i])
		{
			result.s[k] = pb->s[tmp_i] - ps->s[i] + carry + '0';
		}
		else if(pb->s[tmp_i] == ps->s[i])
		{
			if(carry == 0)
			{
				result.s[k] = '0';
			}
			else
			{
				carry = -1;
				result.s[k] = pb->s[tmp_i] - ps->s[i] + 10 + carry + '0';
			}
		}
		else
		{
			result.s[k] = pb->s[tmp_i] - ps->s[i] + 10 + carry + '0';
			carry = -1;
		}
		k++;
		tmp_i--;
	}
	if(tmp_i != pb->size - ps->size - 1)
	{
		cout << "WRONG IN PURE" <<endl;
	}
	for (int i = pb->size - ps->size - 1; i >= 0; i--)
	{
		if(pb->s[i] == '0' && carry == -1)
		{
			result.s[k] = '9';
		}
		else
		{
			result.s[k] = pb->s[i] + carry;
		}
		k++;
		if(k >= pb->size + 1)
		{
			cout << "WRONG IN PURESUB"<<endl;
		}
	}
	BigInt finalSub;
	result.s[k] = '\0';
	result.size = k;
	delete[] finalSub.s;
	finalSub.s = new char[k + 1];
	int j = 0;
	for (int i = k-1; i >= 0; i--)
	{
		finalSub.s[j] = result.s[i];
		j++;
	}
	finalSub.size = result.size;
	finalSub.isMinus = result.isMinus;
	finalSub.isZero = result.isZero;
	finalSub.s[j] = '\0';
	finalSub.removeZero();
	return finalSub;
}

void BigInt::removeZero()
{
	if(s[0] == '0')
	{
		if(isZero == true)
		{
			size = 1;
			isMinus = false;
			delete[] s;
			s = new char[2];
			s[0] = '0';
			s[1] = '\0';
			return;
		}
		BigInt* tmp;
		tmp = new BigInt(0);
		int i = 0;
		while(s[i] == '0')
		{
			i++;
		}
		delete[] tmp->s;
		int tmp_size = size - i;
		tmp->s = new char[tmp_size + 1];
		int k = 0;
		for (int j = i; j <= size-1; j++)
		{
			tmp->s[k] = s[j];
			k++;
		}
		tmp->size = tmp_size;
		tmp->isZero = false;
		tmp->isMinus = isMinus;
		tmp->s[tmp_size] = '\0';
		*this = *tmp;
		delete tmp;
	}
	else
	{
		return;
	}
}

BigInt& BigInt::operator-=(const BigInt& other)
{
	*this = *this - other;
	return *this;
}

BigInt BigInt::operator-(const BigInt& other)
{
	BigInt tmp;
	if(isMinus == false && other.isMinus == true)
	{
		tmp = pureSum(*this, other);
		tmp.isMinus = false;
	}
	else if(isMinus == true && other.isMinus == false)
	{
		tmp = pureSum(*this, other);
		tmp.isMinus = true;
	}
	else if(isMinus == false && other.isMinus == false)
	{
		tmp = pureSub(*this, other);
	}
	else
	{
		tmp = pureSub(other, *this);
	}
	return tmp;
}

