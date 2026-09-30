class Solution:
    def findAllRecipes(self, recipes: List[str], ingredients: List[List[str]], supplies: List[str]) -> List[str]:
        can_cook = {}
        n = len(recipes)
        
        visited = {}

        def dfs(recipe: str) -> bool:
            if recipe in can_cook:
                return True
            if recipe in supplies:
                return True
            if recipe in visited:
                return False

            visited[recipe] = True
            
            index = -1
            for i in range(n):
                if recipes[i] == recipe:
                    index = i
                    break

            if index == -1:
                return False
            
            for ingredient in ingredients[index]:
                if not dfs(ingredient):
                    return False
            
            can_cook[recipe] = True
            return True

        return [r for r in recipes if dfs(r)]
        