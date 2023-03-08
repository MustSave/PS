def solution(people, limit):
    people.sort()
    
    # initialize two pointers at the start and end of the list
    left, right = 0, len(people) - 1
    
    # initialize a counter for the number of boats needed
    num_boats = 0
    
    while left <= right:
        # check if the heaviest and lightest people can fit on a boat
        if people[left] + people[right] <= limit:
            left += 1  # move the lightest person onto the boat
        right -= 1  # move the heaviest person onto the boat
        
        # increment the boat counter
        num_boats += 1
    
    return num_boats