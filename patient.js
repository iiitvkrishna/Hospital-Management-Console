// Patient Dashboard JavaScript
function showSection(sectionId) {
    // Hide all sections
    const sections = document.querySelectorAll('.section');
    sections.forEach(section => {
        section.classList.remove('active');
    });
    
    // Show selected section
    document.getElementById(sectionId).classList.add('active');
}

function logout() {
    if (confirm('Are you sure you want to logout?')) {
        window.location.href = 'index.html';
    }
}

// Handle appointment form submission
document.getElementById('appointment-form').addEventListener('submit', function(e) {
    e.preventDefault();
    
    const formData = {
        doctor: document.getElementById('doctor').value,
        date: document.getElementById('date').value,
        time: document.getElementById('time').value,
        reason: document.getElementById('reason').value
    };
    
    // Here you would typically send this data to your backend
    console.log('Appointment data:', formData);
    
    alert('Appointment booked successfully!');
    this.reset();
});

// Set minimum date to today
document.getElementById('date').min = new Date().toISOString().split('T')[0];