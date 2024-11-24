from chatterbot import ChatBot
from chatterbot.trainers import ChatterBotCorpusTrainer
from chatterbot.trainers import ListTrainer
chatbot=ChatBot('equinox bot')
trainer = ChatterBotCorpusTrainer(chatbot)

trainer.train("chatterbot.corpus.english.greetings","chatterbot.corpus.english.conversations","chatterbot.corpus.english" )

trainer = ListTrainer(chatbot)

trainer.train([

    "What is Equinox ?",

    "Equinox is a competitions oragnised by department of Computer Engineering of KKWIEER",

])

trainer.train([

    "Which events are oragnised by Equinox?",

    "Web battles, Shutterburg, Ideathon, Project Wars, Furious Finder",

])

trainer.train([

    "How can I register ?",

    "Visit to White Port.",

])
trainer.train([

    "ok",

    "What else can I help you ?",

])

trainer.train([

    "tell me a random number",

    "1",
    "2",
    "3",
    "4",
    "5",
    "6",
    "7",
    "8",
    "9",
    "0",

])

exit_conditions = (":q", "quit", "exit","bye","shutdown")			


while True:
	query = input("You>>")
	if query in exit_conditions:
		print("See you again, Good bye!! :)")
		break
	response = chatbot.get_response(query)
	print("ChatBot>>",response)

