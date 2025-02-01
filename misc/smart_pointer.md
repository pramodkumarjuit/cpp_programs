Smart pointers are a feature in C++ that automate memory management by ensuring that
dynamically allocated objects are properly deleted when they are no longer needed. 

They help prevent memory leaks, dangling pointers, and double deletions.

Smart pointers are part of the C++ Standard Library (<memory> header) and include:
- std::unique_ptr – Sole ownership.
- std::shared_ptr – Shared ownership (reference counting).
- std::weak_ptr – Non-owning reference to avoid circular references.


Feature	std::unique_ptr	std::shared_ptr	std::weak_ptr
----------------------------------------------------
Ownership	    Exclusive	Shared	Non-owning
Copy Allowed	❌ No	    ✅ Yes	✅ Yes
Move Allowed	✅ Yes	    ✅ Yes	✅ Yes
Reference Count	❌ No	    ✅ Yes	❌ No
Prevents Leaks	✅ Yes	    ✅ Yes	✅ Yes
Avoids Cycles	✅ Yes	    ❌ No	✅ Yes

