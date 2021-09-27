for var in {1..5}
do
	./philo 200 400 400 400 > tmp
	grep "sagmentation" tmp
	rm tmp
done
