#pragma once
#include "template_vector.h"
#include "rational.h"

template<typename T>class        numeric_vector_;
// typedef numeric_vector_<F64> vector_f64;
typedef numeric_vector_<F64> vector_f64;
typedef numeric_vector_<F32> vector_f32;
typedef numeric_vector_<I32> vector_i32;

template<typename T>
class numeric_vector_: public template_vector_<T>
{
public:
	numeric_vector_<T>&      normalize ();
	numeric_vector_<T>       normalized()const;
	T                        magnitude ()const;
	static T                 dot       (const numeric_vector_<T>& lhs, const numeric_vector_<T>& rhs);
	static numeric_vector_<T>direction (const numeric_vector_<T>& lhs, const numeric_vector_<T>& rhs);
	static numeric_vector_<T>gradient  (std::function<T(const numeric_vector_<T>&)> func, numeric_vector_<T>& x, const T&   accuracy);
	static T                 partial   (std::function<T(const numeric_vector_<T>&)> func, numeric_vector_<T>& x, const I32 index, const T& accuracy);
	static T                 partial2  (std::function<T(const numeric_vector_<T>&)> func, numeric_vector_<T>& x, const I32 index1, const I32 index2, const T& accuracy);

	numeric_vector_<T>& operator+=(const numeric_vector_<T>& rhs);
	numeric_vector_<T>& operator-=(const numeric_vector_<T>& rhs);
	numeric_vector_<T>& operator*=(const numeric_vector_<T>& rhs);
	numeric_vector_<T>& operator/=(const numeric_vector_<T>& rhs);

	numeric_vector_<T>& operator+=(const T& rhs);
	numeric_vector_<T>& operator-=(const T& rhs);
	numeric_vector_<T>& operator*=(const T& rhs);
	numeric_vector_<T>& operator/=(const T& rhs);

	numeric_vector_<T> operator[](const slice& slc);
	const numeric_vector_<T> operator[](const slice& slc)const;
	const T& operator[](const I32 index)const;
	T& operator[](const I32 index);

	numeric_vector_<T>& operator=(const numeric_vector_<T>& lhs);
	numeric_vector_<T>& operator=(numeric_vector_<T>&& lhs)noexcept;

	template<typename T>friend bool operator==(const numeric_vector_<T>& lhs, const numeric_vector_<T>& rhs);
	template<typename T>friend bool operator!=(const numeric_vector_<T>& lhs, const numeric_vector_<T>& rhs);
	
	template<typename T>friend bool operator>(const numeric_vector_<T>& lhs, const numeric_vector_<T>& rhs);
	template<typename T>friend bool operator<(const numeric_vector_<T>& lhs, const numeric_vector_<T>& rhs);

	template<typename T>friend bool operator>=(const numeric_vector_<T>& lhs, const numeric_vector_<T>& rhs);
	template<typename T>friend bool operator<=(const numeric_vector_<T>& lhs, const numeric_vector_<T>& rhs);
	
	template<typename T>friend bool operator >(const T& lhs, const numeric_vector_<T>& rhs);
	template<typename T>friend bool operator <(const T& lhs, const numeric_vector_<T>& rhs);

	template<typename T>friend bool operator>=(const T& lhs, const numeric_vector_<T>& rhs);
	template<typename T>friend bool operator<=(const T& lhs, const numeric_vector_<T>& rhs);

	template<typename T>friend bool operator>(const numeric_vector_<T>& lhs, const T& rhs);
	template<typename T>friend bool operator<(const numeric_vector_<T>& lhs, const T& rhs);

	template<typename T>friend bool operator>=(const numeric_vector_<T>& lhs, const T& rhs);
	template<typename T>friend bool operator<=(const numeric_vector_<T>& lhs, const T& rhs);
	/*
	*/
	template<typename T>friend numeric_vector_<T> operator+(const numeric_vector_<T>& lhs, const numeric_vector_<T>& rhs);
	template<typename T>friend numeric_vector_<T> operator-(const numeric_vector_<T>& lhs, const numeric_vector_<T>& rhs);
	template<typename T>friend numeric_vector_<T> operator*(const numeric_vector_<T>& lhs, const numeric_vector_<T>& rhs);
	template<typename T>friend numeric_vector_<T> operator/(const numeric_vector_<T>& lhs, const numeric_vector_<T>& rhs);

	template<typename T>friend numeric_vector_<T> operator+(const T& lhs, const numeric_vector_<T>& rhs);
	template<typename T>friend numeric_vector_<T> operator-(const T& lhs, const numeric_vector_<T>& rhs);
	template<typename T>friend numeric_vector_<T> operator*(const T& lhs, const numeric_vector_<T>& rhs);
	template<typename T>friend numeric_vector_<T> operator/(const T& lhs, const numeric_vector_<T>& rhs);

	template<typename T>friend numeric_vector_<T> operator+(const numeric_vector_<T>& lhs, const T& rhs);
	template<typename T>friend numeric_vector_<T> operator-(const numeric_vector_<T>& lhs, const T& rhs);
	template<typename T>friend numeric_vector_<T> operator*(const numeric_vector_<T>& lhs, const T& rhs);
	template<typename T>friend numeric_vector_<T> operator/(const numeric_vector_<T>& lhs, const T& rhs);

	template<typename T>friend std::ostream& operator<<(std::ostream& stream, const numeric_vector_<T>& rhs);

	numeric_vector_(const template_vector_<T>& src) : template_vector_<T>(src) {
	};

	numeric_vector_(template_vector_<T>&& src) : template_vector_<T>(src) {
	};

	numeric_vector_(numeric_vector_<T>&& vector)noexcept : template_vector_<T>(vector) {
	};

	numeric_vector_(const numeric_vector_<T>& vector) : template_vector_<T>(vector) {
	};

	numeric_vector_(const I32 cap, const bool default_fill = true) : template_vector_<T>(cap) {
		if(default_fill)template_vector_<T>::fill([](const I32 n) {return T{ 0 }; });
	};

	numeric_vector_(const initializer_list<T>& values) : template_vector_<T>(values) {
	};

	// template< typename... Args>
	// numeric_vector_(T val, Args... values) :template_vector_<T>(val, values...){};

	numeric_vector_() : template_vector_<T>() {
	};

protected:
	numeric_vector_(const slice& slice, template_vector_<T>& source) : template_vector_<T>(slice, source) {
	};
	template<typename T1, typename T2>
	numeric_vector_(const map_values<T1, T2>& values) : template_vector_<T2>(values) {
	};
	template<typename T1, typename T2>
	numeric_vector_(const combine_values<T1, T2>& values) : template_vector_<T2>(values) {
	};
};

template<typename T>
inline numeric_vector_<T>& numeric_vector_<T>::normalize()
{
	return  ((*this) *= (T{ 1.0 } / magnitude()));
}

template<typename T>
inline numeric_vector_<T> numeric_vector_<T>::normalized() const
{
	return numeric_vector_<T>(combine_values<T, T>(this->values(), T{1.0} / magnitude(), mul_f));
}

template<typename T>
inline T numeric_vector_<T>::magnitude() const
{
	return T(std::sqrt(numeric_vector_<T>::reduce([](const T& accum, const T& value) {return accum + value * value; })));
}

template<typename T>
inline T numeric_vector_<T>::dot(const numeric_vector_<T>& lhs, const numeric_vector_<T>& rhs)
{
	T val = T{ 0 };
	for (const pair_<T, T>& pair : template_vector_<T>::template zip<T>(lhs, rhs)) val += pair.first * pair.second;
	return val;
}

template<typename T>
inline numeric_vector_<T> numeric_vector_<T>::direction(const numeric_vector_<T>& lhs, const numeric_vector_<T>& rhs)
{
	return (rhs - lhs).normalize();
}

template<typename T>
inline numeric_vector_<T> numeric_vector_<T>::gradient(std::function<T(const numeric_vector_<T>&)> func, numeric_vector_<T>& x, const T& accuracy)
{
	numeric_vector_<T> grad(x.filling());
	grad.apply_enumerate([&](const I32 index, const T& value) {return numeric_vector_<T>::partial(func, x, index, accuracy); });
	return grad;
}

template<typename T>
inline T numeric_vector_<T>::partial(std::function<T(const numeric_vector_<T>&)> func, numeric_vector_<T>& x, const I32 index, const T& accuracy)
{
	assert(x.in_range(index) && "index value out of vector indices rannge");
	x.unchecked_access(index) = x.unchecked_access(index) + accuracy;
	const T f_r               = func(x);
	x.unchecked_access(index) = x.unchecked_access(index) - T{ 2.0 } * accuracy;
	const T f_l               = func(x);
	x.unchecked_access(index) = x.unchecked_access(index) + accuracy;
	return (f_r - f_l) / accuracy * T{ 0.5 };
}

template<typename T>
inline T numeric_vector_<T>::partial2(std::function<T(const numeric_vector_<T>&)> func, numeric_vector_<T>& x, const I32 index1, const I32 index2, const T& accuracy)
{
	assert(x.in_range(index2) && "index value out of vector indices rannge");
	// return partial([&](const numeric_vector_<T>& v) {return partial(func, x, index1);}, x, index1);
	x.unchecked_access(index2) = x.unchecked_access(index2) + accuracy;
	const T f_r                = numeric_vector_<T>::partial(func, x, index1, accuracy);
	x.unchecked_access(index2) = x.unchecked_access(index2) - T{ 2.0 } * accuracy;
	const T f_l                = numeric_vector_<T>::partial(func, x, index1, accuracy);
	x.unchecked_access(index2) = x.unchecked_access(index2) + accuracy;
	return (f_r - f_l) / accuracy * T{ 0.5 };
}

template<typename T>
inline numeric_vector_<T>& numeric_vector_<T>::operator+=(const numeric_vector_<T>& rhs)
{
	assert(this->filling() == rhs.filling() && "operator += :: vector with not equal sizes");
	template_vector_<T>::apply(combine_values<T, T>(this->values(), rhs.values(), sum_f));
	return (*this);
}

template<typename T>
inline numeric_vector_<T>& numeric_vector_<T>::operator-=(const numeric_vector_<T>& rhs)
{
	assert(this->filling() == rhs.filling() && "operator -= :: vector with not equal sizes");
	template_vector_<T>::apply(combine_values<T, T>(this->values(), rhs.values(), dif_f));
	return (*this);
}

template<typename T>
inline numeric_vector_<T>& numeric_vector_<T>::operator*=(const numeric_vector_<T>& rhs)
{
	assert(this->filling() == rhs.filling() && "operator *= :: vector with not equal sizes");
	template_vector_<T>::apply(combine_values<T, T>(this->values(), rhs.values(), mul_f));
	return (*this);
}

template<typename T>
inline numeric_vector_<T>& numeric_vector_<T>::operator/=(const numeric_vector_<T>& rhs)
{
	assert(this->filling() == rhs.filling() && "operator /= :: vector with not equal sizes");
	template_vector_<T>::apply(combine_values<T, T>(this->values(), rhs.values(), div_f));
	return (*this);
}

template<typename T>
inline numeric_vector_<T>& numeric_vector_<T>::operator+=(const T& rhs)
{
	template_vector_<T>::apply(combine_values<T, T>(this->values(), rhs, sum_f));
	return (*this);
}

template<typename T>
inline numeric_vector_<T>& numeric_vector_<T>::operator-=(const T& rhs)
{
	template_vector_<T>::apply(combine_values<T, T>(this->values(), rhs, dif_f));
	return (*this);
}

template<typename T>
inline numeric_vector_<T>& numeric_vector_<T>::operator*=(const T& rhs)
{
	template_vector_<T>::apply(combine_values<T, T>(this->values(), rhs, mul_f));
	return (*this);
}

template<typename T>
inline numeric_vector_<T>& numeric_vector_<T>::operator/=(const T& rhs)
{
	template_vector_<T>::apply(combine_values<T, T>(this->values(), T{ 1.0 } / rhs, mul_f));
	return (*this);
}

template<typename T>
inline numeric_vector_<T> numeric_vector_<T>::operator[](const slice& slc)
{
	return numeric_vector_<T>(slc, *this);
}

template<typename T>
inline const numeric_vector_<T> numeric_vector_<T>::operator[](const slice& slc)const
{
	return numeric_vector_<T>(slc, *this);
}

template<typename T>
inline const T& numeric_vector_<T>::operator[](const I32 index) const
{
	return template_vector_<T>::operator[](index);
}

template<typename T>
inline T& numeric_vector_<T>::operator[](const I32 index)
{
	return template_vector_<T>::operator[](index);
}

template<typename T>
inline numeric_vector_<T>& numeric_vector_<T>::operator=(const numeric_vector_<T>& lhs)
{
	template_vector_<T>::reassign_data((const template_vector_<T>&)lhs);
	return (*this);
}

template<typename T>
inline numeric_vector_<T>& numeric_vector_<T>::operator=(numeric_vector_<T>&& lhs)noexcept
{
	template_vector_<T>::exchange_data((template_vector_<T>&&)lhs);
	return (*this);
}

template<typename T>
inline bool operator==(const numeric_vector_<T>& lhs, const numeric_vector_<T>& rhs)
{
	assert(lhs.filling() == rhs.filling() && "compare operator :: vector with not equal sizes");
	const zip_values<T, T> zip_vals = zip_values<T, T>(lhs.values(), rhs.values());
	for (const pair_<T, T>& pair : zip_vals) if (pair.first != pair.second) return false;
	return true;
}

template<typename T>
inline bool operator!=(const numeric_vector_<T>& lhs, const numeric_vector_<T>& rhs)
{
	return !(lhs == rhs);
}

template<typename T>
inline bool operator>(const numeric_vector_<T>& lhs, const numeric_vector_<T>& rhs)
{
	assert(lhs.filling() == rhs.filling() && "operator > :: vector with not equal sizes");
	const zip_values<T, T> zip_vals = zip_values<T, T>(lhs.values(), rhs.values());
	for (const pair_<T, T>& pair : zip_vals) if (pair.first <= pair.second) return false;
	return true;
}

template<typename T>
inline bool operator<(const numeric_vector_<T>& lhs, const numeric_vector_<T>& rhs)
{
	assert(lhs.filling() == rhs.filling() && "operator < :: vector with not equal sizes");
	const zip_values<T, T> zip_vals = zip_values<T, T>(lhs.values(), rhs.values());
	for (const pair_<T, T>& pair : zip_vals) if (pair.first >= pair.second) return false;
	return true;
}

template<typename T>
inline bool operator>=(const numeric_vector_<T>& lhs, const numeric_vector_<T>& rhs)
{
	return !(lhs < rhs);
}

template<typename T>
inline bool operator<=(const numeric_vector_<T>& lhs, const numeric_vector_<T>& rhs)
{
	return !(lhs > rhs);
}

template<typename T>
inline bool operator>(const T& lhs, const numeric_vector_<T>& rhs)
{
	for (const pair_<T, T>& pair : zip_values<T, T>(lhs, rhs.values())) if (pair.first <= pair.second) return false;
	return true;
}

template<typename T>
inline bool operator<(const T& lhs, const numeric_vector_<T>& rhs)
{
	for (const pair_<T, T>& pair : zip_values<T, T>(lhs, rhs.values())) if (pair.first >= pair.second) return false;
	return true;
}

template<typename T>
inline bool operator>=(const T& lhs, const numeric_vector_<T>& rhs)
{
	return !(lhs < rhs);
}

template<typename T>
inline bool operator<=(const T& lhs, const numeric_vector_<T>& rhs)
{
	return !(lhs > rhs);
}

template<typename T>
inline bool operator>(const numeric_vector_<T>& lhs, const T& rhs)
{
	for (const pair_<T, T>& pair : zip_values<T, T>(lhs.values(), rhs)) if (pair.first <= pair.second) return false;
	return true;
}

template<typename T>
inline bool operator<(const numeric_vector_<T>& lhs, const T& rhs)
{
	for (const pair_<T, T>& pair : zip_values<T, T>(lhs.values(), rhs)) if (pair.first >= pair.second) return false;
	return true;
}

template<typename T>
inline bool operator>=(const numeric_vector_<T>& lhs, const T& rhs)
{
	return !(lhs < rhs);
}

template<typename T>
inline bool operator<=(const numeric_vector_<T>& lhs, const T& rhs)
{
	return !(lhs > rhs);
}

template<typename T>
inline numeric_vector_<T> operator+(const numeric_vector_<T>& lhs, const numeric_vector_<T>& rhs)
{
	assert(lhs.filling() == rhs.filling() && "operator + :: vector with not equal sizes");
	const combine_values<T, T> combine_vals = combine_values<T, T>(lhs.values(), rhs.values(), sum_f);
	return numeric_vector_<T>(combine_vals);
}

template<typename T>
inline numeric_vector_<T> operator-(const numeric_vector_<T>& lhs, const numeric_vector_<T>& rhs)
{
	assert(lhs.filling() == rhs.filling() && "operator - :: vector with not equal sizes");
	const combine_values<T, T> combine_vals = combine_values<T, T>(lhs.values(), rhs.values(), dif_f);
	return numeric_vector_<T>(combine_vals);
}

template<typename T>
inline numeric_vector_<T> operator*(const numeric_vector_<T>& lhs, const numeric_vector_<T>& rhs)
{
	assert(lhs.filling() == rhs.filling() && "operator * :: vector with not equal sizes");
	const combine_values<T, T> combine_vals = combine_values<T, T>(lhs.values(), rhs.values(), mul_f);
	return numeric_vector_<T>(combine_vals);
}

template<typename T>
inline numeric_vector_<T> operator/(const numeric_vector_<T>& lhs, const numeric_vector_<T>& rhs)
{
	assert(lhs.filling() == rhs.filling() && "operator / :: vector with not equal sizes");
	const combine_values<T, T> combine_vals = combine_values<T, T>(lhs.values(), rhs.values(), div_f);
	return numeric_vector_<T>(combine_vals);
}

template<typename T>
inline numeric_vector_<T> operator+(const T& lhs, const numeric_vector_<T>& rhs)
{
	return numeric_vector_<T>(combine_values<T, T>(lhs, rhs.values(), sum_f));
}

template<typename T>
inline numeric_vector_<T> operator-(const T& lhs, const numeric_vector_<T>& rhs)
{
	return numeric_vector_<T>(combine_values<T, T>(lhs, rhs.values(), dif_f));
}

template<typename T>
inline numeric_vector_<T> operator*(const T& lhs, const numeric_vector_<T>& rhs)
{
	return numeric_vector_<T>(combine_values<T, T>(lhs, rhs.values(), mul_f));
}

template<typename T>
inline numeric_vector_<T> operator/(const T& lhs, const numeric_vector_<T>& rhs)
{
	return numeric_vector_<T>(combine_values<T, T>(lhs, rhs.values(), div_f));
}

template<typename T>
inline numeric_vector_<T> operator+(const numeric_vector_<T>& lhs, const T& rhs)
{
	return numeric_vector_<T>(combine_values<T, T>(lhs.values(), rhs, sum_f));
}

template<typename T>
inline numeric_vector_<T> operator-(const numeric_vector_<T>& lhs, const T& rhs)
{
	return numeric_vector_<T>(combine_values<T, T>(lhs.values(), rhs, dif_f));
}

template<typename T>
inline numeric_vector_<T> operator*(const numeric_vector_<T>& lhs, const T& rhs)
{
	return numeric_vector_<T>(combine_values<T, T>(lhs.values(), rhs, mul_f));
}

template<typename T>
inline numeric_vector_<T> operator/(const numeric_vector_<T>& lhs, const T& rhs)
{
	return numeric_vector_<T>(combine_values<T, T>(lhs.values(), rhs, div_f));
}

template<typename T>
inline std::ostream& operator << (std::ostream& stream, const numeric_vector_<T>& rhs)
{
	stream << "[";
#ifdef RATIONAL_NUMBERS_REPRESNTATION
	for (I32 index = 0; index < rhs.size(); index++)
	{
		stream << std::setw(NUMBER_CHARS_COUNT) << rational::rational_str(rhs.unchecked_access(index), false);
		stream << (index == rhs.size() - 1 ? "" : ",");
	}
#else
	for (I32 index = 0; index < rhs.size(); index++)
	{
		stream << std::setw(NUMBER_CHARS_COUNT) << rhs.unchecked_access(index);
		stream << (index == rhs.size() - 1 ? "" : ",");
	}
#endif // RATIONAL_NUMBERS_REPRESNTATION
	stream << "]";
	return stream;
}

auto test_f = [](const vector_f64& vector)
{
	F64 result = 0.0;
	I32 index = 1;
	for (auto v : vector.values())
	{
		result += index * (v - index - 1) * (v - index - 1);
	}
	return result;
};

void numeric_vector_test();

void numeric_vector_test()
{
	vector_f64 lhs({ 1.0, 2.0, 3.0, 4.0, 9.0, 8.0, 7.0, 6.0 });
	vector_f64 rhs({ 9.0, 8.0, 7.0, 6.0, 1.0, 2.0, 3.0, 4.0 });
	// rhs.push_back(9.0).push_back(8.0).push_back(7.0).push_back(6.0);
	std::cout << "lhs            : " << lhs << "\n";
	std::cout << "rhs            : " << rhs << "\n";
	std::cout << "rhs - copy     : " << vector_f64(rhs) << "\n";
	std::cout << "lhs + rhs      : " << lhs + rhs << "\n";
	std::cout << "lhs - rhs      : " << lhs - rhs << "\n";
	std::cout << "lhs * rhs      : " << lhs * rhs << "\n";
	std::cout << "lhs / rhs      : " << lhs / rhs << "\n";

	std::cout << "2 + rhs        : " << 2.0 + rhs << "\n";
	std::cout << "2 - rhs        : " << 2.0 - rhs << "\n";
	std::cout << "2 * rhs        : " << 2.0 * rhs << "\n";
	std::cout << "2 / rhs        : " << 2.0 / rhs << "\n";
							     
	std::cout << "rhs + 2        : " << rhs + 2.0 << "\n";
	std::cout << "rhs - 2        : " << rhs - 2.0 << "\n";
	std::cout << "rhs * 2        : " << rhs * 2.0 << "\n";
	std::cout << "rhs / 2        : " << rhs / 2.0 << "\n";
								 
	std::cout << "lhs += rhs     : " << (lhs += rhs) << "\n";
	std::cout << "lhs -= rhs     : " << (lhs -= rhs) << "\n";
	std::cout << "lhs *= rhs     : " << (lhs *= rhs) << "\n";
	std::cout << "lhs /= rhs     : " << (lhs /= rhs) << "\n";
								 
	std::cout << "lhs += 2.0     : " << (lhs += 2.0) << "\n";
	std::cout << "lhs -= 2.0     : " << (lhs -= 2.0) << "\n";
	std::cout << "lhs *= 2.0     : " << (lhs *= 2.0) << "\n";
	std::cout << "lhs /= 2.0     : " << (lhs /= 2.0) << "\n";
	std::cout << "mag(lhs)       : " << rational::rational_number(lhs.magnitude()) << "\n";
	std::cout << "dot(lhs, rhs)  : " << rational::rational_number(vector_f64::dot(lhs, rhs)) << "\n";
	std::cout << "dir(lhs, rhs)  : " << vector_f64::direction(lhs, rhs) << "\n";
	std::cout << "normalized(lhs): " << lhs.normalized() << "\n";
	std::cout << "normalize (lhs): " << lhs.normalize() << "\n";
	std::cout << "gradient  (lhs): " << vector_f64::gradient(test_f, lhs, 1e-9) << "\n";
	std::cout << "partial2  (lhs): " << rational::rational_number(vector_f64::partial2(test_f, lhs,0,0, 1e-9)) << "\n";
	std::cout << "lhs == rhs     : " << (lhs == rhs) << "\n";
	std::cout << "lhs != rhs     : " << (lhs != rhs) << "\n";
	std::cout << "lhs > rhs      : " << (lhs > rhs) << "\n";
	std::cout << "lhs < rhs      : " << (lhs < rhs) << "\n";
	std::cout << "lhs >= rhs     : " << (lhs >= rhs) << "\n";
	std::cout << "lhs <= rhs     : " << (lhs <= rhs) << "\n";
	std::cout << "lhs >= 100     : " << (lhs >= 100.0) << "\n";
	std::cout << "lhs <= 100     : " << (lhs <= 100.0) << "\n";
	std::cout << "lhs            : "  << lhs << "\n";
	lhs[slice(3, 6)] = vector_f64({ 13.0, 13.0, 13.0 });
	std::cout << "lhs            : " << lhs << "\n";

}
