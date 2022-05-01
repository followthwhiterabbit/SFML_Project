#ifndef RESOURCEHOLDER_H
#define RESOURCEHOLDER_H

#include <map>
#include <string>
#include <memory>
#include <stdexcept>
#include <cassert>  // defines one macro function that can be used as a standard debugging tool 






template< typename Resource, typename Identifier> 
class ResourceHolder
{
public:
	void load(Identifier id, const std::string& filename); // takes the id and the filename as string 

	template<typename Parameter> 
	void load(Identifier id, const std::string& filename, const Parameter& secondParam); 

	Resource& get(Identifier id); 













};










#endif // !RESOURCEHOLDER_H
