document.getElementById('current-year-gaurang').textContent = new Date().getFullYear();

const searchInput = document.getElementById('searchInput');
const searchButton = document.getElementById('searchButton');
const skeletonLoader = document.getElementById('skeletonLoader');
const mainContent = document.getElementById('mainContent');
const noResultsMessage = document.getElementById('noResultsMessage');

function showLoader() {
    mainContent.classList.add('hidden');
    noResultsMessage.classList.add('hidden-message');
    skeletonLoader.classList.remove('hidden');
}

function hideLoaderAndShowContent() {
    skeletonLoader.classList.add('hidden');
    mainContent.classList.remove('hidden');
}

window.addEventListener('load', () => {
    showLoader();
    setTimeout(() => {
        hideLoaderAndShowContent();
        document.querySelectorAll('.card').forEach(card => {
            card.style.display = 'block';
        });
    }, 1000);
});

searchButton.addEventListener('click', performSearch);
searchInput.addEventListener('keypress', function(event) {
    if (event.key === 'Enter') {
        performSearch();
    }
});

function performSearch() {
    const searchInputValue = searchInput.value.toLowerCase();
    const cards = document.querySelectorAll('.card');
    
    showLoader();

    setTimeout(() => {
        let foundResults = false;

        cards.forEach(card => {
            const cardTitleElement = card.querySelector('.card__job-title');
            if (cardTitleElement) { // Check if the element exists
                const jobTitle = cardTitleElement.textContent.toLowerCase();
                if (jobTitle.includes(searchInputValue)) {
                    card.style.display = 'block';
                    foundResults = true;
                } else {
                    card.style.display = 'none';
                }
            }
        });

        hideLoaderAndShowContent();

        if (foundResults) {
            noResultsMessage.classList.add('hidden-message');
        } else {
            noResultsMessage.classList.remove('hidden-message');
            noResultsMessage.scrollIntoView({ behavior: 'smooth', block: 'start' });
        }
    }, 800);
}