select id, amount, dense_rank() over (order by amount desc) as ranking
from ex_card