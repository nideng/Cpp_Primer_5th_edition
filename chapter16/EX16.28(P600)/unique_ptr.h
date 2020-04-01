#include"DebugDelete.h"
namespace EX16_28_b
{
	template<typename, typename>class unique_ptr;
	template<typename T, typename U>
	void swap(unique_ptr<T, U>& lhs, unique_ptr<T, U>& rhs);
	
	
	template<typename T,typename U=DebugDelete>
	class unique_ptr
	{
		friend void swap<T,U>(unique_ptr<T, U>& lhs, unique_ptr<T, U>& rhs);
	public:
		unique_ptr(const unique_ptr&) = delete;
		unique_ptr& operator=(const unique_ptr&) = delete;
		unique_ptr() = default;
		explicit unique_ptr(T* ptr):pointer(ptr){}
		explicit unique_ptr(T* ptr,const U& u):pointer(ptr),deleter(u){}
		unique_ptr(unique_ptr&& upt)noexcept 
			:pointer(upt.pointer),deleter(upt.deleter)
		{ 
			upt.pointer = nullptr; 
		}
		unique_ptr& operator=(unique_ptr&& rhs)noexcept
		{
			if (pointer != rhs.pointer)
			{
				deleter(pointer);
				pointer = nullptr;
				EX16_28_b::swap(*this, rhs);
			}
			return *this;
		}
		unique_ptr& operator=(std::nullptr_t n)
		{
			if (n == nullptr)
			{
				deleter(pointer);
				pointer = nullptr;
			}
			return *this;
		}

		T& operator* ()const { return *pointer; }
		T* operator->()const { return &*pointer; }
		operator bool()const { return pointer ? true : false; }
		T* get()const noexcept { return pointer; }
		void  swap(unique_ptr<T, U>& rhs) { EX16_28_b::swap(*this, rhs); }
		void reset()noexcept
		{
			deleter(pointer);
			pointer = nullptr;
		}
		void reset(T* p)noexcept
		{
			if (pointer != p)
			{
				deleter(pointer);
				pointer = p;
			}
		}
		T* release()
		{
			T* ptr = pointer;
			pointer = nullptr;
			return ptr;
		}
		~unique_ptr()
		{
			deleter(pointer);
		}
	private:
		T* pointer = nullptr;
		U deleter=U();
	};
	template<typename T,typename U>
	void swap(unique_ptr<T, U>& lhs, unique_ptr<T, U>& rhs)
	{
		using std::swap;
		swap(lhs.pointer, rhs.pointer);
		swap(lhs.deleter, rhs.deleter);
	}
}

