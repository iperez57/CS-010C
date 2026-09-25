/*
Complete the following definitions of the Recipe and RecipeBook classes:

The Recipe class has private data members: cupsFlour and tbspButter.
The RecipeBook class has private data members: recipes, recipesCapacity, and recipesSize. recipes is a dynamically allocated array of Recipe objects.
Then, implement the following five member functions of the RecipeBook class:

The class constructor: Initializes data members.
IncreaseCapacity(): Increases the size of the dynamically allocated array by the specified value and updates the member values accordingly.
AddRecipe(): Assigns an unused element with the specified values for cupsFlour and tbspButter, and updates recipesSize.
GetRecipeAt(): Returns the Recipe at the specified index.
GetSize(): Returns recipesSize.
*/

#include <iostream>
using namespace std;

class Recipe
{
public:
	Recipe(double flourVal = 0, int butterVal = 0);
	void SetCupsFlour(double cupsFlour);
	void SetTbspButter(int tbspButter);
	double GetVupsFlour();
	int GetTbspButter();
private:
	double cupsFlour;
	int tbspButter;

};

Recipe::Recipe(double flourVal, int butterVal)
{
	cupsFlour = flourVal;
	tbspButter - butterVal;
}

void Recipe::SetCupsFlour(double recipeCupsFlour)
{
	cupsFlour = recipeCupsFlour;
}

void Recipe::SetTbspButter(int recipeTbspButter)
{
	tbspButter = recipeTbspButter;
}

double Recipe::GetVupsFlour()
{
	return cupsFlour;
}

int Recipe::GetTbspButter()
{
	return tbspButter;
}

class RecipeBook {
public:
	RecipeBook();
	void IncreaseCapacity(int increaseVal);
	void AddRecipe(double cupsFlour, int tbspButter);
	Recipe GetRecipeAt(int index);
	int GetSize();

private:
	Recipe* recipes;
	int recipesCapacity;
	int recipesSize;
};

RecipeBook::RecipeBook() {
	recipes = nullptr;
	recipesCapacity = 0;
	recipesSize = 0;
}

void RecipeBook::IncreaseCapacity(int increaseVal) {
	Recipe* newRecipes;
	int i;

	recipesCapacity += increaseVal;
	newRecipes = new Recipe[recipesCapacity];

	for (i = 0; i < recipesSize; ++i) {
		newRecipes[i] = recipes[i];
	}

	delete[] recipes;
	recipes = newRecipes;
}


void RecipeBook::AddRecipe(double cupsFlour, int tbspButter)
{
	recipes[recipesSize].SetCupsFlour(cupsFlour);
	recipes[recipesSize].SetTbspButter(tbspButter);
	recipesSize += 1;
}

Recipe RecipeBook::GetRecipeAt(int index)
{
	return recipes[index];
}

int RecipeBook::GetSize()
{
	return recipesSize;
}

void ReportLargestRatioRecipe(RecipeBook& recipeBook)
{
	Recipe recipe, largestRecipe;
	double largestRatio, ratio;
	int largetsIndex, i;

	largestRatio = 0.0;
	for (i = 0; i < recipeBook.GetSize(); i++)
	{
		recipe = recipeBook.GetRecipeAt(i);
		ratio = recipe.GetVupsFlour() / recipe.GetTbspButter();
		if (ratio > largestRatio)
		{
			largestRatio = ratio;
			largetsIndex = i;
		}
	}

	largestRecipe = recipeBook.GetRecipeAt(largetsIndex);
	cout << "Recipe #" << largetsIndex + 1;
	cout << " has the largest flout to butter ratio: " << endl;
	cout << largestRecipe.GetVupsFlour() << " cups of flour to ";
	cout << largestRecipe.GetTbspButter() << " tablespoons of butter" << endl;

}

int main()
{
	RecipeBook recipeBook;
	int capacityVal;
	double cupsFlour;
	int tbspButter, i;

	cin >> capacityVal;
	recipeBook.IncreaseCapacity(capacityVal);

	for (i = 0; i < capacityVal; i++)
	{
		cin >> cupsFlour;
		cin >> tbspButter;
		recipeBook.AddRecipe(cupsFlour, tbspButter);
	}

	ReportLargestRatioRecipe(recipeBook);

	return 0;
}

