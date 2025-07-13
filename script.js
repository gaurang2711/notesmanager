
document.getElementById('current-year-gaurang').textContent = new Date().getFullYear();


document.getElementById('searchButton').addEventListener('click', function() {
    const searchInput = document.getElementById('searchInput').value.toLowerCase();
    const cards = document.querySelectorAll('.card');
    const noResultsMessage = document.getElementById('noResultsMessage');
    const cardsContainer = document.querySelector('.cards-container'); 

    let foundResults = false; 

    cards.forEach(card => {
        const jobTitle = card.querySelector('.card__job-title').textContent.toLowerCase();
        if (jobTitle.includes(searchInput)) {
            card.style.display = 'block'; 
            foundResults = true; 
        } else {
            card.style.display = 'none'; 
        }
    });

    
    if (foundResults) {
        noResultsMessage.classList.add('hidden-message');
    } else {
        noResultsMessage.classList.remove('hidden-message'); 
        
        cardsContainer.scrollIntoView({ behavior: 'smooth', block: 'start' });
    }
});