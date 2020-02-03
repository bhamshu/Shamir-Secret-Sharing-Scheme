#include<bits/stdc++.h>
using namespace std;
class GF256Element { 
//encapsulates elements in GF(2^8)
//irreducible polynomial: x^8 + x^4 + x^3 + x + 1
//a generator: 0x03
	static uint8_t DiscreteLog(uint8_t i){
		//for generator 3.
		static std::vector<uint8_t> discrete_log = {
			0, 255, 25, 1, 50, 2, 26, 198, 75, 199, 27, 104, 51, 238, 
			223, 3, 100, 4, 224, 14, 52, 141, 129, 239, 76, 113, 8, 
			200, 248, 105, 28, 193, 125, 194, 29, 181, 249, 185, 39, 
			106, 77, 228, 166, 114, 154, 201, 9, 120, 101, 47, 138, 5, 
			33, 15, 225, 36, 18, 240, 130, 69, 53, 147, 218, 142, 150, 
			143, 219, 189, 54, 208, 206, 148, 19, 92, 210, 241, 64, 70,
			131, 56, 102, 221, 253, 48, 191, 6, 139, 98, 179, 37, 226, 
			152, 34, 136, 145, 16, 126, 110, 72, 195, 163, 182, 30, 66, 
			58, 107, 40, 84, 250, 133, 61, 186, 43, 121, 10, 21, 155, 
			159, 94, 202, 78, 212, 172, 229, 243, 115, 167, 87, 175,
			88, 168, 80, 244, 234, 214, 116, 79, 174, 233, 213, 
			231, 230, 173, 232, 44, 215, 117, 122, 235, 22, 11, 
			245, 89, 203, 95, 176, 156, 169, 81, 160, 127, 12,
			246, 111, 23, 196, 73, 236, 216, 67, 31, 45, 164, 118, 
			123, 183, 204, 187, 62, 90, 251, 96, 177, 134, 59, 82, 161,
			108, 170, 85, 41, 157, 151, 178, 135, 144, 97, 190, 220, 252,
			188, 149, 207, 205, 55, 63, 91, 209, 83, 57, 132, 60, 65, 162,
			109, 71, 20, 42, 158, 93, 86, 242, 211, 171, 68, 17, 146, 217,
			35, 32, 46, 137, 180, 124, 184, 38, 119, 153, 227, 165, 103, 74,
			237, 222, 197, 49, 254, 24, 13, 99, 140, 128, 192, 247, 112, 7 
		};
		return discrete_log[i];
	}
	static uint8_t Exponent(uint8_t i) {
		static std::vector<uint8_t> exp = {
			0, 3, 5, 15, 17, 51, 85, 255, 26, 46, 114, 150, 161, 248, 19, 53,
			95, 225, 56, 72, 216, 115, 149, 164, 247, 2, 6, 10, 30, 34, 102,
			170, 229, 52, 92, 228, 55, 89, 235, 38, 106, 190, 217, 112, 144, 
			171, 230, 49, 83, 245, 4, 12, 20, 60, 68, 204, 79, 209, 104, 184, 211, 
			110, 178, 205, 76,
			212, 103, 169, 224, 59, 77, 215, 98, 166, 241, 8, 24, 40, 120, 136, 131, 
			158, 185, 208, 107, 189, 220, 127, 129, 152, 179, 206, 73, 219, 118, 154, 
			181, 196, 87, 249, 16, 
			48, 80, 240, 11, 29, 39, 105, 187, 214, 97, 163, 254, 25, 43, 125, 135, 146,
			173, 236, 47, 113, 147, 174, 233, 32, 96, 160, 251, 22, 58, 78, 210, 109, 183, 
			194, 93, 231, 50, 86, 250, 21, 63, 65, 195, 94, 226, 61, 71, 201, 64, 
			192, 91, 237, 44, 116, 156, 191, 218, 117, 159, 186, 213, 100, 172, 239, 42, 126,
			130, 157, 188, 223, 122, 142, 137, 128, 155, 182, 193, 88, 232, 35, 101, 175, 234,
			37, 111, 177, 200, 67, 197, 84, 252, 31, 33, 99, 165, 244, 7, 9, 27, 
			45, 119, 153, 176, 203, 70, 202, 69, 207, 74, 222, 121, 139, 134, 145, 168, 227,
			62, 66, 198, 81, 243, 14, 18, 54, 90, 238, 41, 123, 141, 140, 143, 138, 133, 148, 
			167, 242, 13, 23, 57, 75, 221, 124, 132, 151, 162, 253, 28, 36, 108, 
			180, 199, 82, 246, 1
		};
		return exp[i];
	}
public:
	uint8_t v;
	
	GF256Element(uint8_t val) : v(val) {
	}	
	GF256Element() {
	}
	GF256Element operator+(GF256Element b2){
		return GF256Element((this->v) ^ (b2.v));
	}
	GF256Element operator-(GF256Element b2){
		//same as addition
		return GF256Element((this->v) ^ (b2.v));
	}
	GF256Element operator*(GF256Element b2) {
		if(this->v == 0 || b2.v == 0)
			return GF256Element(0);
		int p = int(DiscreteLog(this->v)) + int(DiscreteLog(b2.v));
		if(p%255==0)
			return GF256Element(1);
		return GF256Element(Exponent(p%255));
	}
	GF256Element operator/(GF256Element b2) {
		assert(b2.v != 0);
		int p = 255 + int(DiscreteLog(this->v)) - int(DiscreteLog(b2.v));
		return GF256Element(Exponent(p%255));	
	}
	static GF256Element getRandomGF256Element() {
		uint8_t u;
		u = (rand()%256);
		return GF256Element(u);
	}
	static GF256Element getGenerator() {
		return GF256Element(3);
	}
};


struct Secret {
	std::vector<uint8_t> byte_array;
	Secret(std::vector<uint8_t>& arg) {
		assert(arg.size() <= 32);
		byte_array.resize(32);
		for (int i = 0; i < arg.size(); i++) {
			byte_array[i] = arg[i];
		}
		for (int i = arg.size(); i < 32; i++ ) {
			byte_array[i] = 0;
		}
	} 
	Secret(std::string s){
		assert(s.size() <= 32);
		byte_array.resize(32);
		for (int i = 0; i < s.size(); i++) {
			byte_array[i] = uint8_t(s[i]);
		}
		for (int i = s.size(); i < 32; i++) {
			byte_array[i] = 0;
		}
	}
	Secret() {
		byte_array.resize(32);
	}
	void show() {
		for (int i = 0; i < 32; i++) {
			cout<<char(byte_array[i]);
		}
		cout<<endl;
	}
	bool operator==(Secret s2) {
		for (int i = 0; i < 32; i++) {
			if(byte_array[i] != s2.byte_array[i])
				return false;
		}
		return true;
	}
};

struct Share {
	Secret X;
	Secret Y;
	Share(){
	}
};


class SSSHelperInterface{
//provides interface for methods needed for Shamir Secret Scheme
  public:
  	virtual std::vector<Share> getShares(Secret) = 0;
  	virtual Secret getSecret(Share, Share) = 0;
};

class SSSHelper : public SSSHelperInterface{ 
//implementation of methods in the interface
	public: 
		SSSHelper(){
		}
		std::vector<Share> getShares(Secret secret) {
			std::vector<Share> ret(4);
			for (int i = 0; i < 32; i++) {
				GF256Element a;
				do{
					a = GF256Element::getRandomGF256Element();
				}while(a.v == 0);
				// acc to y = ax+b
				GF256Element b = GF256Element(secret.byte_array[i]);
				unordered_set<uint8_t> takenx;
				//cout<<char(b.v)<<" ";
				for (int j = 0; j < 4; j++) {
					GF256Element x;
					do{
						x = GF256Element::getRandomGF256Element();
					}while(x.v == 0 || takenx.count(x.v));
					GF256Element y = ((a*x) + b); // y = ax + b
					//assert(((y-b)/a).v == x.v);
					//cout<<int(x.v)<<" .";
					takenx.insert(x.v);
					ret[j].X.byte_array[i] = x.v;
					ret[j].Y.byte_array[i] = y.v;
				}
			}
			return ret;
		}
		Secret getSecret(Share s1, Share s2) {
			Secret ret;
			for (int i = 0; i < 32; i++) {
				GF256Element x1 = GF256Element(s1.X.byte_array[i]),
						y1 = GF256Element(s1.Y.byte_array[i]),
						x2 = GF256Element(s2.X.byte_array[i]),
						y2 = GF256Element(s2.Y.byte_array[i]);
				GF256Element a = (y2 - y1)/(x2 - x1);  //slope
				GF256Element b = (y1 - (a*x1)); // y = ax + b; b = y - ax
				ret.byte_array[i] = b.v;
			}
			return ret;
		}
};

int main() {
	srand(time(NULL));
	SSSHelper H;
	Secret secret("The purpose of Universe is ~!:@>");
	std::vector<Share> shares = H.getShares(secret);
	Secret retrieved = H.getSecret(shares[1], shares[0]);
	assert(retrieved == secret);
	retrieved.show();
	return 0;
} 


// //from wikipedia: 
// 	uint8_t p = 0; /* the product of the multiplication */
// 	uint8_t a = v, b = b2.v;
// 	while (a && b) {
//             if (b & 1) /* if b is odd, then add the corresponding a to p (final product = sum of all a's corresponding to odd b's) */
//                 p ^= a; /* since we're in GF(2^m), addition is an XOR */

//             if (a & 0x80)  GF modulo: if a >= 128, then it will overflow when shifted left, so reduce 
//                 a = (a << 1) ^ 0x11b; /* XOR with the primitive polynomial x^8 + x^4 + x^3 + x + 1 (0b1_0001_1011) – you can change it but it must be irreducible */
//             else
//                 a <<= 1; /* equivalent to a*2 */
//             b >>= 1; /* equivalent to b // 2 */
// 	}
// 	return byte(p);
// }
/****************************************

To generate discrete log table:

unordered_map<uint8_t, uint8_t> discrete_log;
byte gen = byte(0x03);
byte walk = gen;
for(uint8_t i = 1; ; i++){
	if(discrete_log.count(walk.v))
		cout<<"................."<<walk.v<<" "<<i<<",.......";
	discrete_log[walk.v] = i;
	cout<<int(i)<<": "<< int(walk.v)<<endl;
	walk = walk * gen;
	if(i == 255)
		break;
}
cout<<int(discrete_log[0])<<" ";
for(uint8_t i = 1; i != 0;i++) {
	cout<<int(discrete_log[i])<<", ";
}

********************************************/