document.getElementById('current-year-gaurang').textContent = new Date().getFullYear();

// Get references to all necessary HTML elements
const searchInput = document.getElementById('searchInput');
const searchButton = document.getElementById('searchButton');
const skeletonLoader = document.getElementById('skeletonLoader');
const mainContent = document.getElementById('mainContent');
const noResultsMessage = document.getElementById('noResultsMessage');
const splashScreen = document.getElementById('splashScreen');
const appContainer = document.getElementById('appContainer');
const splashSound = document.getElementById('splashSound');
const startButton = document.getElementById('startButton');

// Elements for user info modal
const usernameDisplay = document.getElementById('usernameDisplay');
const userModalOverlay = document.getElementById('userModalOverlay');
const userModalContent = document.getElementById('userModalContent');
const userNameInput = document.getElementById('userNameInput');
const userBirthdateInput = document.getElementById('userBirthdateInput');
const saveUserBtn = document.getElementById('saveUserBtn');

// Function to show a custom message box instead of alert()
function showMessageBox(message, type = 'error') {
    const messageBox = document.createElement('div');
    messageBox.textContent = message;
    messageBox.style.cssText = `
        position: fixed;
        top: 50%;
        left: 50%;
        transform: translate(-50%, -50%);
        padding: 15px 25px;
        border-radius: 8px;
        box-shadow: 0 5px 15px rgba(0,0,0,0.2);
        z-index: 10001;
        font-family: Ubuntu;
        font-size: 1rem;
        text-align: center;
        ${type === 'error' ? 'background-color: #ffdddd; color: #d8000c; border: 1px solid #d8000c;' : 'background-color: #d4edda; color: #155724; border: 1px solid #28a745;'}
    `;
    document.body.appendChild(messageBox);
    setTimeout(() => {
        messageBox.remove();
    }, 3000);
}

// Function to show the user info modal
function showUserModal() {
    console.log("Attempting to show user modal...");
    userModalOverlay.classList.remove('hidden');
    userModalContent.classList.remove('hidden');
    userModalContent.classList.add('visible');
    console.log("User modal classes added: overlay hidden=", userModalOverlay.classList.contains('hidden'), " content hidden=", userModalContent.classList.contains('hidden'), " content visible=", userModalContent.classList.contains('visible'));
}

// Function to hide the user info modal
function hideUserModal() {
    console.log("Attempting to hide user modal...");
    userModalContent.classList.remove('visible');
    setTimeout(() => {
        userModalOverlay.classList.add('hidden');
        userModalContent.classList.add('hidden');
        console.log("User modal hidden after transition.");
    }, 300);
}

// Function to save user data to localStorage
function saveUserData(name, birthdate) {
    localStorage.setItem('userName', name);
    localStorage.setItem('userBirthdate', birthdate);
    console.log("User data saved to localStorage:", { name, birthdate });
    updateUsernameDisplay();
}

// Function to update the displayed username and birthdate
function updateUsernameDisplay() {
    const name = localStorage.getItem('userName');
    console.log("Checking localStorage for user data. Name:", name);
    if (name) {
        usernameDisplay.textContent = `Hello, ${name}!`;
        usernameDisplay.classList.remove('hidden');
        console.log("Username display updated and visible.");
    } else {
        usernameDisplay.classList.add('hidden');
        console.log("No user data found in localStorage, username display hidden.");
    }
}

// Event listener for the "Save & Continue" button in the modal
saveUserBtn.addEventListener('click', () => {
    console.log("Save button clicked.");
    const name = userNameInput.value.trim();
    const birthdate = userBirthdateInput.value;

    // --- New validation for username length ---
    if (name.length > 6) {
        showMessageBox("Username cannot exceed 6 characters.", 'error');
        console.log("Validation failed: Username too long.");
        return; // Stop execution if validation fails
    }
    // --- End new validation ---

    if (name && birthdate) {
        saveUserData(name, birthdate);
        hideUserModal();
    } else {
        console.log("Validation failed: Name or birthdate missing.");
        showMessageBox("Please enter both your name and birthdate.", 'error');
    }
});


// Function to handle the transition from splash screen to app content
function startAppTransition() {
    console.log("startAppTransition called.");
    // Play sound only if not already played in this session
    if (sessionStorage.getItem('splashSoundPlayed') !== 'true') {
        splashSound.play().catch(error => {
            console.error("Error playing splash sound:", error);
        });
        sessionStorage.setItem('splashSoundPlayed', 'true'); // Mark sound as played for this session
    }

    splashScreen.classList.add('splash-hidden');
    console.log("Splash screen hidden class added.");
    
    setTimeout(() => {
        appContainer.classList.remove('hidden');
        skeletonLoader.classList.remove('hidden');
        console.log("App container and skeleton loader now visible.");
        
        setTimeout(() => {
            skeletonLoader.classList.add('hidden');
            mainContent.classList.remove('hidden');
            console.log("Skeleton hidden, main content visible.");
            document.querySelectorAll('.card').forEach(card => {
                card.style.display = 'block';
            });

            // Check for user data and show modal if needed
            console.log("Checking localStorage for userName after content load...");
            if (!localStorage.getItem('userName')) {
                console.log("userName NOT found in localStorage. Showing user modal.");
                showUserModal();
            } else {
                console.log("userName found in localStorage. Updating username display.");
                updateUsernameDisplay();
            }

        }, 700);
        
    }, 200);
}

// Initial Page Load Logic - Using DOMContentLoaded for faster initial display
document.addEventListener('DOMContentLoaded', () => {
    console.log("DOMContentLoaded fired. Initializing page.");

    // Check if splash screen has already been shown in this session
    if (sessionStorage.getItem('splashScreenShown') === 'true') {
        console.log("Splash screen already shown in this session. Bypassing splash.");
        document.body.classList.remove('hidden'); // Reveal body immediately
        splashScreen.classList.add('splash-hidden'); // Ensure splash is hidden
        appContainer.classList.remove('hidden'); // Show app container immediately
        skeletonLoader.classList.remove('hidden'); // Show skeleton immediately

        // Proceed directly to showing main content after a short delay
        setTimeout(() => {
            skeletonLoader.classList.add('hidden');
            mainContent.classList.remove('hidden');
            document.querySelectorAll('.card').forEach(card => {
                card.style.display = 'block';
            });
            // Check for user data and show modal if needed
            if (!localStorage.getItem('userName')) {
                showUserModal();
            } else {
                updateUsernameDisplay();
            }
        }, 500); // Short delay to ensure elements are rendered before hiding skeleton
        
        // Also ensure the start button is hidden if splash is bypassed
        startButton.classList.add('hidden-button');
        startButton.classList.remove('visible');

    } else {
        console.log("First visit in session. Showing splash screen.");
        document.body.classList.remove('hidden'); // Reveal body to show splash screen
        splashScreen.classList.remove('splash-hidden'); // Make sure splash is visible
        appContainer.classList.add('hidden'); // Keep app container hidden initially

        // After 0.3 seconds, make the "Enter NoteSense" button visible
        setTimeout(() => {
            startButton.classList.remove('hidden-button');
            startButton.classList.add('visible');
            console.log("Start button made visible.");
        }, 300);

        // Set the flag in sessionStorage once the splash screen process begins
        sessionStorage.setItem('splashScreenShown', 'true');
    }
});

// Attach the event listener to the "Enter NoteSense" button
startButton.addEventListener('click', startAppTransition);


// Search functionality
searchButton.addEventListener('click', performSearch);
searchInput.addEventListener('keypress', function(event) {
    if (event.key === 'Enter') {
        performSearch();
    }
});

function performSearch() {
    console.log("Performing search...");
    const searchInputValue = searchInput.value.toLowerCase();
    const cards = document.querySelectorAll('.card');
    
    mainContent.classList.add('hidden');
    noResultsMessage.classList.add('hidden-message');
    skeletonLoader.classList.remove('hidden');
    console.log("Search: Main content hidden, skeleton visible.");

    setTimeout(() => {
        let foundResults = false;

        cards.forEach(card => {
            const cardTitleElement = card.querySelector('.card__job-title');
            if (cardTitleElement) {
                const jobTitle = cardTitleElement.textContent.toLowerCase();
                if (jobTitle.includes(searchInputValue)) {
                    card.style.display = 'block';
                    foundResults = true;
                } else {
                    card.style.display = 'none';
                }
            }
        });

        skeletonLoader.classList.add('hidden');
        mainContent.classList.remove('hidden');
        console.log("Search: Skeleton hidden, main content visible with results.");

        if (foundResults) {
            noResultsMessage.classList.add('hidden-message');
            console.log("Search: Results found.");
        } else {
            noResultsMessage.classList.remove('hidden-message');
            noResultsMessage.scrollIntoView({ behavior: 'smooth', block: 'start' });
            console.log("Search: No results found.");
        }
    }, 800);
}

function udt(){
    const now = new Date();
    const dTE = document.getElementById('Date');

    const opt = {weekday: 'long', year: 'numeric', month: 'long', day: 'numeric', hour: '2-digit', minute: '2-digit', second: '2-digit'};
    dTE.innerHTML = now.toLocaleString(undefined, opt);
}

udt();


setInterval(udt, 1000);