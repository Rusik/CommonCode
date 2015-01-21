//
// Copyright (c) 2015 Ruslan Kavetsky
//
// Based on: https://github.com/VTPG/CommonCode
//           http://vgable.com/blog/2010/08/19/the-most-useful-objective-c-code-ive-ever-written/

NSString *VTPG_DDToStringFromTypeAndValue(const char *typeCode, void *value);

#define LOG_EXPR(_X_) do { \
		__typeof__(_X_) _Y_ = (_X_); \
		const char *_TYPE_CODE_ = @encode(__typeof__(_X_)); \
		NSString *_STR_ = VTPG_DDToStringFromTypeAndValue(_TYPE_CODE_, &_Y_); \
		if (_STR_) \
			NSLog(@"%s = %@", #_X_, _STR_); \
		else \
			NSLog(@"Unknown _TYPE_CODE_: %s for expression %s in function %s, file %s, line %d", _TYPE_CODE_, #_X_, __func__, __FILE__, __LINE__); \
} while (0)
g