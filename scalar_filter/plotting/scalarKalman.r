data <- read.table("~/Documents/STAR/Kalman Filter/kalman/scalar_filter/plotting/rust_out.txt", header = TRUE, sep = ",", dec = ".")

plot(
    data$Iteration, data$Estimate,
    col = "red",
    ylim = range(15:31),
    xlab = "Iteration", ylab = "Estimated Temperature",
    main = "Kalman Filter simulation",
    type = "l"
)
points(data$Iteration, data$Measurement)
abline(h=data$Real)
legend("topleft", 
       legend = c("Estimate", "Measurement"), 
       col = c("red", "black"),
       pch=c(1,1))
