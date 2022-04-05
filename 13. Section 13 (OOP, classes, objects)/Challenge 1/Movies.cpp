/*** 
The Movies class represents a collection of Movie objects as a std::vector called "movies" (attribute)

Please refer to the reference material of Section 13 for the main.cpp, Movie.h, Movie.cpp and Movies.h files that are required
for this project. These files include:
1) main.cpp: tests to run and two helper functions
2) Movie.h: private member fields (3), public: constructor with 3 attributes, copy constructor, destructor, setters + getters for 
   private attributes (setters + getters implemented inline, getters use const qualifiers as best practice), watch count increment method 
   (implemented inline) and display() const method
3) Movie.cpp: constructor implementation, copy constructor implementation with no post instantiation assignment, destructor implementation, 
   display() const method implementation 
4) Movies.h: private fields (vector of Movie objects), public: constructor, destructor and member methods implemented in this file (Movies.cpp)  
***/

#include <iostream>
#include "Movies.h"

// Movies constructor implementation (reference solution, provided by instructor)
Movies::Movies() {
}

// Movies destructor implementation (reference solution, provided by instructor)
Movies::~Movies() {
}

/*** add_movie will search the vector (attribute) of the Movies object to check whether the Movie object is already there.
     Therefore, if it already exists, we return false (no need to add the same movie). 
     Otherwise, create a new Movie object and return true. ***/
bool Movies::add_movie(std::string name, std::string rating, int watched) {
    // Remember to return at the end of the scope 
    // Note: for efficiency, use & (otherwise we'll check the name of a copied Movie object) 
    for(const Movie &movie: movies){
        if(movie.get_name() == name)
            return false;
    }
    Movie new_movie {name, rating, watched};
    movies.push_back(new_movie);
    return true;
}

/*** increment_watched will search the vector (attribute) of Movies to see if there's a Movie object with the 
     name we need. If so, increment_watched will increment the watch count by 1 and return true. 
     Otherwise, it will return false. ***/
bool Movies::increment_watched(std::string name) {
   // NOTE: if we don't use & here, then the watch count of the copied object will be incremented instead so
   // the watch count of the original object in the vector won't be incremented. 
    for(Movie &movie:movies){ 
        if (movie.get_name() == name){
                movie.increment_watched();
                return true; 
        }
    }
    return false; 
}


/*** This method only displays the Movie objects in our Movies object (in the member vector to be precise) 
     A Movie object also has a display method (please refer to the reference material of Section 13). ***/
void Movies::display() const {
   if (movies.size() == 0){
        std::cout << "Sorry, no movies to display" << std::endl;  
   }else{ 
       std::cout << "*************************************" << std::endl; 
       for(const Movie &movie: movies){
            movie.display();
       }
       std::cout << "*************************************" << std::endl; 
   }
}