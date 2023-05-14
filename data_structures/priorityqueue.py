class PriorityQueueElement:
    def __init__(self, name: str, priority: int) -> None:
        self.name = name
        self.priority = priority

    def __str__(self) -> str:
        return f'Element value: {self.name}. Element priority: {self.priority}'


class PriorityQueue:
    def __init__(self) -> None:
        self.queue: list[PriorityQueueElement] = []

    def get_size(self) -> int:
        return self.queue.__len__()

    def __get_insertion_index__(self, element: PriorityQueueElement) -> int:
        for index in range(self.get_size()):
            if (element.priority < self.queue[index].priority):
                return index
        return -1

    def enqueue(self, elements: list[PriorityQueueElement]) -> bool:
        for element in elements:
            insertion_index = self.__get_insertion_index__(element)
            if (insertion_index == -1):
                self.queue.append(element)
            else:
                self.queue.insert(insertion_index, element)

    def dequeue(self) -> PriorityQueueElement:
        if (self.get_size() > 0):
            return self.queue.pop(0)

    def __iter__(self):
        return self

    def __next__(self):
        if self.get_size() == 0:
            raise StopIteration
        return self.queue.pop(0)


elements = [PriorityQueueElement("a", 2), PriorityQueueElement("f", 8), PriorityQueueElement("b", 1), PriorityQueueElement(
    "c", 3), PriorityQueueElement("d", 0), PriorityQueueElement("h", 10), PriorityQueueElement("i", 5), PriorityQueueElement("j", 4), PriorityQueueElement("g", 8), PriorityQueueElement("z", 15), PriorityQueueElement("u", 6)]

queue = PriorityQueue()
queue.enqueue(elements)

queue.enqueue([PriorityQueueElement("x", 28)])

for element in queue:
    print(element)
